//
//  Copyright (C) 2015  bitstream
//
//  Based on a reference implementation provided by Wolfgang Spraul and
//  Project Icestorm by Clifford Wolf <clifford@clifford.at>
//
//  Permission to use, copy, modify, and/or distribute this software for any
//  purpose with or without fee is hereby granted, provided that the above
//  copyright notice and this permission notice appear in all copies.
//
//  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
//  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
//  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
//  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
//  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
//  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//


#include "helper.h"
#include "spartan6die.h"


int log_level = 0;

using std::vector;
using std::string;


// on die each row has 	3 block types
//	block 0				xc6_get_frame_data_len(die) bytes logic +
//	block 1				xc6_get_bram_data_len(die) bytes bram+
//	block 2				xc6_get_iob_data_len(die) bytes io buffers
// in bitstream  frame data has addition 2 frames per row padding
// 
// each frame row is 505 frames (is this different per die?) of 65 words (2 bytes),
// 1 frame is 16 CLBs (64 bit per CLB)
// 1 frame = 1 minor = 16 rows (4 words=64bits) + center (HCLK = 1 word)
//
// Majors
// MAJ_ZERO - not known what called in torc/xilinx doc
//   4 minors Wolf leaves this mysterious comment 505 bytes = middle 8-bit for each minor?
//   First Major in the row, wolf has before LTERM?
//   decoded as 
//		num-minor * 16 bit clock bits (512 to 528 bits are termed clock bits by Wolf)
//		Rest is decoded as unknown
// MAJ_LEFT, MAJ_RIGHT AKA LTERM, RTERM
//   30 minors 
//   Marks LEFT or RIGHT of a row
//   decoded as 
//		num-minor * 16 bit clock bits (512 to 528 bits are termed clock bits by Wolf)
//		Rest is decoded as unknown
// MAJ_LOGIC_XM, MAJ_LOGIC_XL, MAJ_CENTER
//   MAJ_LOGIC_XM = 30 minors,  MAJ_LOGIC_XL & MAJ_CENTER = 31 minors, 
//   CLB logic bloks
//   decoded as 
//		num-minor * 16 bit clock bits (512 to 528 bits are termed clock bits by Wolf)
//		20 minors = 10 routing pairs * 2 frames
//		1 minor = mi20 (unknown)
//		IF( TOP OR BOTTOM IO section)
//			14 rows 
//			decode extra data
//		ELSE
//			16 rows
//		IF( MAJ_LOGIC_XM )
//			M logic = read rows lut 4 words from each of minor 21 and 24
//			X logic = read rows lut 4 words from each of minor 27 and 29
//		ELSE
//			L logic = read rows lut 4 words from each of minor 21 and 23
//			X logic = read rows lut 4 words from each of minor 26 and 28
//		iF( MAJ_CENTER)
//			read extra frame from minor 30
// ==================================================================
// FpgaConfig stuff

int extract_switches( const Spartan6Die& die, Spartan6Instance& instance )
{
	int x, y;

	for (x = 0; x < die->num_tile_cols; x++) {
		for (y = 0; y < die->num_tile_rows; y++) {

			const auto tile = die.tile_coord_lookup[ getTileIndex(x,y) ];

			// are we in the 'main' part of the chip
			if( !die->inBottomIO(y) && die->inTopIO(y) ){
			}

			// routing switches
			if (is_atx(X_ROUTING_COL, es->model, x)
			    && y >= TOP_IO_TILES
			    && y < es->model->y_height-BOT_IO_TILES
			    && !is_aty(Y_ROW_HORIZ_AXSYMM|Y_CHIP_HORIZ_REGS,
					es->model, y)) {
				extract_routing_switches(es, y, x);
			}
			// logic switches
			if (has_device(es->model, y, x, DEV_LOGIC)) {
				extract_logic_switches(es, y, x);
			}
			// iologic switches
			if (has_device(es->model, y, x, DEV_ILOGIC)) {
				extract_iologic_switches(es, y, x);
			}
		}
	}
//	extract_center_switches(es);
//	extract_gclk_center_vert_sw(es);
//	extract_gclk_hclk_updown_sw(es);
}

struct FpgaConfig
{
	IdCode idcode;

	// icebox i/o
	void read_ascii(std::istream &ifs);
	void write_ascii(std::ostream &ofs) const;


	uint64_t current_frame;
};

void FpgaConfig::read_ascii(std::istream &ifs)
{
	debug("## %s\n", __PRETTY_FUNCTION__);
	info("Parsing ascii file..\n");

	bool got_device = false;
	IdCode idcode;
	bool reuse_line = true;
	string line, command;

	while (reuse_line || getline(ifs, line))
	{
		reuse_line = false;

		std::istringstream is(line);
		is >> command;

		if (command.empty())
			continue;

		debug("Next command: %s\n", line.c_str());

		if (command == ".comment")
		{
			// comments currently ignored
			while (getline(ifs, line))
			{
				if (line.substr(0, 1) == ".") {
					reuse_line = true;
					break;
				}
			}
			continue;
		}

		if (command == ".device")
		{
			if (got_device)
				error("More than one .device statement.\n");

			string device;

			is >> device;
			debug( "Device = %s\n", device.c_str() );
			idcode = from_string( device );

			got_device = true;
			continue;

		}

		if (command == ".iob_tile")
		{
			if (!got_device)
				error("Missing .device statement before %s.\n", command.c_str());

			int tile_x, tile_y;
			is >> tile_x >> tile_y;
		}

		if (command == ".tile")
		{
			if (!got_device)
				error("Missing .device statement before %s.\n", command.c_str());

			int tile_x, tile_y, minors;
			is >> tile_x >> tile_y >> minors;

			for (int minor = 0; minor < minors && getline(ifs, line); minor++) {
				uint8_t bits[64];
				memset( bits, 0, 64 );

				int cur_bit = 0;
				for (int bit_y = 0; bit_y < 16 && getline(ifs, line); bit_y++) {
					if (line.substr(0, 1) == ".") {
						reuse_line = true;
						break;
					}

					for (int bit_x = 0; bit_x < int(line.size()) && bit_x < cic.tile_width; bit_x++) {
						if (line[bit_x] == '1') {
							current_frame
							bits[cur_bit] = 1;
						}
						cur_bit++;
					}
				}			
			}
/*
			CramIndexConverter cic(this, tile_x, tile_y);

			if (("." + cic.tile_type + "_tile") != command)
				error("Got %s statement for %s tile %d %d.\n",
						command.c_str(), cic.tile_type.c_str(), tile_x, tile_y);

*/

			continue;
		}

	}

	assert( false );
}

void FpgaConfig::write_ascii(std::ostream &ofs) const
{
	debug("## %s\n", __PRETTY_FUNCTION__);
	info("Writing ascii file..\n");

	ofs << ".device " << to_string(idcode) << std::endl;
	assert( false );
}

// ==================================================================
// Main program

void usage()
{
	log("\n");
	log("Usage: sixpack [options] [input-file [output-file]]\n");
	log("\n");
	log("    -u\n");
	log("        unpack mode (implied when called as 'iceunpack')\n");
	log("\n");
	log("    -v\n");
	log("        verbose (repeat to increase verbosity)\n");
	log("\n");
	exit(1);
}

int main(int argc, char **argv)
{
	vector<string> parameters;
	bool unpack_mode = false;

	for (int i = 0; argv[0][i]; i++)
		if (string(argv[0]+i) == "sixunpack")
			unpack_mode = true;

	for (int i = 1; i < argc; i++)
	{
		string arg(argv[i]);

		if (arg[0] == '-' && arg.size() > 1) {
			for (int i = 1; i < int(arg.size()); i++)
				if (arg[i] == 'u') {
					unpack_mode = true;
				} else if (arg[i] == 'v') {
					log_level++;
				} else
					usage();
			continue;
		}

		parameters.push_back(arg);
	}

	std::ifstream ifs;
	std::ofstream ofs;

	std::istream *isp;
	std::ostream *osp;

	if (parameters.size() >= 1 && parameters[0] != "-") {
		ifs.open(parameters[0], std::ios::binary);
		if (!ifs.is_open())
			error("Failed to open input file.\n");
		isp = &ifs;
	} else {
		isp = &std::cin;
	}

	if (parameters.size() >= 2 && parameters[1] != "-") {
		ofs.open(parameters[1], std::ios::binary);
		if (!ofs.is_open())
			error("Failed to open output file.\n");
		osp = &ofs;
	} else {
		osp = &std::cout;
	}

	if (parameters.size() > 2)
		usage();

	FpgaConfig fpga_config;

	if (unpack_mode) {
//		fpga_config.read_bits(*isp);
//		fpga_config.write_ascii(*osp);
	} else {
		fpga_config.read_ascii(*isp);
//		fpga_config.write_bits(*osp);
	}

	info("Done.\n");
	return 0;
}

