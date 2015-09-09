//
//  Copyright (C) 2015  Dean Calver
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
void usage()
{
	log("\n");
	log("Usage: sixpack [options] [input-file [output-file]]\n");
	log("\n");
	log("    -v\n");
	log("        verbose (repeat to increase verbosity)\n");
	log("\n");
	exit(1);
}

int main(int argc, char **argv)
{
	vector<string> parameters;

	for (int i = 1; i < argc; i++)
	{
		string arg(argv[i]);

		if (arg[0] == '-' && arg.size() > 1) {
			for (int i = 1; i < int(arg.size()); i++)
				if (arg[i] == 'v') {
					log_level++;
				} else
					usage();
			continue;
		}

		parameters.push_back(arg);
	}

	std::ofstream ofs;
	std::ostream *osp;


	if (parameters.size() >= 1 && parameters[1] != "-") {
		ofs.open(parameters[0], std::ios::binary);
		if (!ofs.is_open())
			error("Failed to open output file.\n");
		osp = &ofs;
	} else {
		osp = &std::cout;
	}

	if (parameters.size() > 1)
		usage();

	const auto& die = get_spartan6_die( IdCode::XC6SLX25 );


	info("Done.\n");
	return 0;
}

