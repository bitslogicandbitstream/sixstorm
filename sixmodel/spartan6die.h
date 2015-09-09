#pragma once

enum class IdCode : uint32_t {
	XC6SLX4 = 0x04000093,
	XC6SLX9 = 0x04001093,
	XC6SLX16 = 0x04002093,
	XC6SLX25 = 0x04004093,
};

std::string to_string( const IdCode idcode );
IdCode from_string( const std::string& str );
// Notes:
// B??? and/or BOT = Bottom
// T??? and/or TOP = Top
// INT = Interconnect AKA Switch Box column AKA Routing
// HCLK = Horizontal CLK (mid Tile rows)
// REGH = Horizontal Center (mid chip)
// REG_V = Vertical Center (mid Tile colounms)
// BRAM = Block RAM
// DSP = DSP
// MACC = DSP
// GTP = Serializer
// IOI = Input Output (Interface?)
// TERM = edge (TOP,BOTTOM,LEFT and RIGHT)
// CMT = PLL
// CL = CLB / Logic

enum class Spartan6TileTypes : uint8_t {
	NULL_TILE,
	BIOB,
	BIOB_SINGLE,
	BIOB_SINGLE_ALT,
	BIOI_INNER,
	BIOI_INNER_UNUSED,
	BIOI_OUTER,
	BIOI_OUTER_UNUSED,
	BRAMSITE2,
	BRAMSITE2_DUMMY,
	BRAM_BOT,
	BRAM_BOT_BTERM_L,
	BRAM_BOT_BTERM_R,
	BRAM_HCLK_FEEDTHRU,
	BRAM_HCLK_FEEDTHRU_FOLD,
	BRAM_HCLK_FEEDTHRU_INTER,
	BRAM_HCLK_FEEDTHRU_INTER_FOLD,
	BRAM_INTER_BTERM,
	BRAM_INTER_TTERM,
	BRAM_INT_INTERFACE_BOT,
	BRAM_INT_INTERFACE_TOP,
	BRAM_REGH_FEEDTHRU,
	BRAM_REGH_FEEDTHRU_INTER,
	BRAM_TOP,
	BRAM_TOP_TTERM_L,
	BRAM_TOP_TTERM_R,
	CLB_EMP_BTERM,
	CLB_INT_BTERM,
	CLEXL,
	CLEXL_DUMMY,
	CLEXM,
	CLEXM_DUMMY,
	CLKC,
	CMT_CAP,
	CMT_DCM2_BOT,
	CMT_DCM2_TOP,
	CMT_DCM_BOT,
	CMT_DCM_TOP,
	CMT_HCLK_BOT25,
	CMT_PLL1_BOT,
	CMT_PLL2_BOT,
	CMT_PLL2_TOP,
	CMT_PLL3_BOT,
	CMT_PLL3_TOP,
	CMT_PLL_BOT,
	CMT_PLL_TOP,
	CNR_BR_BTERM,
	CNR_TL_LTERM,
	CNR_TR_RTERM,
	CNR_TR_TTERM,
	DSP_BOT_BTERM_L,
	DSP_BOT_BTERM_R,
	DSP_CLB_HCLK_FEEDTHRU,
	DSP_CLB_HCLK_FEEDTHRU_FOLD,
	DSP_EMP_BOT,
	DSP_EMP_TEMP,
	DSP_EMP_TOP,
	DSP_HCLK_FEEDTHRU_TOP,
	DSP_HCLK_GCLK_FOLD,
	DSP_HCLK_GCLK_NOFOLD,
	DSP_INTER_TTERM,
	DSP_INT_BTERM,
	DSP_INT_EMP_BOT,
	DSP_INT_EMP_TOP,
	DSP_INT_HCLK_FEEDTHRU,
	DSP_INT_HCLK_FEEDTHRU_FOLD,
	DSP_INT_TTERM,
	DSP_TOP_TTERM_L,
	DSP_TOP_TTERM_R,
	EMP_LIOB,
	EMP_RIOB,
	GTPDUAL_BOT,
	GTPDUAL_BOT_UNUSED,
	GTPDUAL_CLB_FEEDTHRU,
	GTPDUAL_DSP_FEEDTHRU,
	GTPDUAL_INT_FEEDTHRU,
	GTPDUAL_LEFT_CLB_FEEDTHRU,
	GTPDUAL_LEFT_DSP_FEEDTHRU,
	GTPDUAL_LEFT_INT_FEEDTHRU,
	GTPDUAL_TOP,
	GTPDUAL_TOP_UNUSED,
	HCLK_BRAM_FEEDTHRU,
	HCLK_BRAM_FEEDTHRU_FOLD,
	HCLK_CLB_XL_CLE,
	HCLK_CLB_XL_CLE_FOLD,
	HCLK_CLB_XL_INT,
	HCLK_CLB_XL_INT_FOLD,
	HCLK_CLB_XM_CLE,
	HCLK_CLB_XM_CLE_FOLD,
	HCLK_CLB_XM_INT,
	HCLK_CLB_XM_INT_FOLD,
	HCLK_IOIL_BOT_DN,
	HCLK_IOIL_BOT_SPLIT,
	HCLK_IOIL_BOT_UP,
	HCLK_IOIL_EMP,
	HCLK_IOIL_INT,
	HCLK_IOIL_INT_FOLD,
	HCLK_IOIL_TOP_DN,
	HCLK_IOIL_TOP_SPLIT,
	HCLK_IOIL_TOP_UP,
	HCLK_IOIR_BOT_DN,
	HCLK_IOIR_BOT_SPLIT,
	HCLK_IOIR_BOT_UP,
	HCLK_IOIR_EMP,
	HCLK_IOIR_INT,
	HCLK_IOIR_INT_FOLD,
	HCLK_IOIR_TOP_DN,
	HCLK_IOIR_TOP_SPLIT,
	HCLK_IOIR_TOP_UP,
	HCLK_IOI_LTERM,
	HCLK_IOI_LTERM_BOT25,
	HCLK_IOI_RTERM,
	HCLK_IOI_RTERM_BOT25,
	INT,
	INT_BRAM,
	INT_BRAM_BRK,
	INT_BRK,
	INT_GCLK,
	INT_INTERFACE,
	INT_INTERFACE_CARRY,
	INT_INTERFACE_IOI,
	INT_INTERFACE_IOI_DCMBOT,
	INT_INTERFACE_LTERM,
	INT_INTERFACE_REGC,
	INT_INTERFACE_RTERM,
	INT_LTERM,
	INT_RTERM,
	INT_TERM,
	INT_TERM_BRK,
	IOI_BTERM,
	IOI_BTERM_BUFPLL,
	IOI_BTERM_CLB,
	IOI_BTERM_REGB,
	IOI_INT,
	IOI_LTERM,
	IOI_LTERM_LOWER_BOT,
	IOI_LTERM_LOWER_TOP,
	IOI_LTERM_UPPER_BOT,
	IOI_LTERM_UPPER_TOP,
	IOI_PCI_CE_LEFT,
	IOI_PCI_CE_RIGHT,
	IOI_RTERM,
	IOI_RTERM_LOWER_BOT,
	IOI_RTERM_LOWER_TOP,
	IOI_RTERM_UPPER_BOT,
	IOI_RTERM_UPPER_TOP,
	IOI_TTERM,
	IOI_TTERM_BUFPLL,
	IOI_TTERM_CLB,
	IOI_TTERM_REGT,
	LIOB,
	LIOB_PCI,
	LIOB_RDY,
	LIOI,
	LIOI_BRK,
	LIOI_INT,
	LIOI_INT_BRK,
	LL,
	LR_LOWER,
	LR_UPPER,
	MACCSITE2,
	MACCSITE2_DUMMY,
	MCB_CAP_CLKPN,
	MCB_CAP_INT,
	MCB_CAP_INT_BRK,
	MCB_CNR_TOP,
	MCB_DUMMY,
	MCB_HCLK,
	MCB_INT,
	MCB_INT_BOT,
	MCB_INT_BOT25,
	MCB_INT_DQI,
	MCB_INT_DUMMY,
	MCB_INT_ULDM,
	MCB_L,
	MCB_L_BOT,
	MCB_MUI0R,
	MCB_MUI0W,
	MCB_MUI1R,
	MCB_MUI1W,
	MCB_MUI2,
	MCB_MUI3,
	MCB_MUI4,
	MCB_MUI5,
	MCB_MUI_DUMMY,
	MCB_REGH,
	PCIE_TOP,
	PCIE_TOP_CLB_FEEDTHRU,
	PCIE_TOP_INT_FEEDTHRU,
	PCIE_TOP_UNUSED,
	RAMB_BOT,
	RAMB_BOT_BTERM,
	RAMB_TOP,
	RAMB_TOP_TTERM,
	REGC_CLE,
	REGC_INT,
	REGH_BRAM_FEEDTHRU,
	REGH_BRAM_FEEDTHRU_L_GCLK,
	REGH_BRAM_FEEDTHRU_R_GCLK,
	REGH_CLEXL_CLE,
	REGH_CLEXL_INT,
	REGH_CLEXL_INT_CLK,
	REGH_CLEXM_CLE,
	REGH_CLEXM_INT,
	REGH_CLEXM_INT_GCLKL,
	REGH_DSP_CLB,
	REGH_DSP_INT,
	REGH_DSP_L,
	REGH_DSP_L_NOCLK,
	REGH_DSP_R,
	REGH_IOI,
	REGH_IOI_BOT25,
	REGH_IOI_LTERM,
	REGH_IOI_RTERM,
	REGH_LIOI_INT,
	REGH_LIOI_INT_BOT25,
	REGH_RIOI,
	REGH_RIOI_BOT25,
	REGH_RIOI_INT,
	REGH_RIOI_INT_BOT25,
	REG_B,
	REG_B_BTERM,
	REG_C_CMT,
	REG_L,
	REG_R,
	REG_T,
	REG_T_TTERM,
	REG_V,
	REG_V_BRK,
	REG_V_BTERM,
	REG_V_HCLK,
	REG_V_HCLKBUF_BOT,
	REG_V_HCLKBUF_TOP,
	REG_V_HCLK_BOT25,
	REG_V_MEMB_BOT,
	REG_V_MEMB_TOP,
	REG_V_MIDBUF_BOT,
	REG_V_MIDBUF_TOP,
	REG_V_TTERM,
	RIOB,
	RIOB_PCI,
	RIOB_RDY,
	RIOI,
	RIOI_BRK,
	TIOB,
	TIOB_SINGLE,
	TIOI_INNER,
	TIOI_INNER_UNUSED,
	TIOI_OUTER,
	UL,
	UR_LOWER,
	UR_UPPER,
};

enum class MajorType : uint8_t {
	NULL_TYPE,
	CLB_XM,
	CLB_XL,
	CLB_XM_FOLD,
	CLB_XL_FOLD,
	DSP,
	BRAM,
	LTERM,
	RTERM,
	CENTER
};


class Tile {
public:

	Tile( uint32_t x, uint32_t y, std::string _name, Spartan6TileTypes _type ) :
		tile_col(x), tile_row(y), name(_name), type(_type){}

	// x is interchangable with col, y with row
	uint32_t& x() { return tile_col; }
	const uint32_t& x() const { return tile_col; }
	uint32_t& y() { return tile_row; }
	const uint32_t& y() const { return tile_row; }

	uint32_t tile_col;
	uint32_t tile_row;
	std::string name;
	Spartan6TileTypes type;
};

class ClockDomain {
public:
	std::vector<MajorType> majors;
	uint16_t center_major_index;
	uint16_t right_major_index;
	uint16_t frame_count;
	uint16_t top_tile_row; // where this clockdomain starts in tile_row coords

	bool inClockDomain( uint16_t y ) const { return y >= top_tile_row && y < top_tile_row+17; }
	uint16_t rowWithinClockDomain( uint16_t y ) const { return y - top_tile_row; }
	bool inBottomOfClockDomain( uint16_t y ) const { return rowWithinClockDomain(y) < 8;}
	bool inTopOfClockDomain( uint16_t y ) const { return rowWithinClockDomain(y) > 8;}
	bool isCenterOfClockDomain( uint16_t y ) const { return rowWithinClockDomain(y) == 8; }

};

// ==================================================================
// Spartan6 die stuff
struct Spartan6Die
{
	Spartan6Die() : num_tile_rows(0), 
					num_tile_cols(0), 
					num_physical_rows(0), 
					num_physical_cols(0),
					been_processed(false),
					num_clb_slices(0),
					num_bram(0),
					num_dsps(0)
	{}

	// data should be filled in by subclass (auto-generated from torc)
	uint16_t num_tile_rows;
	uint16_t num_tile_cols;
	uint16_t num_physical_rows;
	uint16_t num_physical_cols;
	std::vector<Tile> tiles;

	bool been_processed;
	void process();

	bool inTopIO( uint16_t y ) const { return y >= num_tile_rows-2; }
	bool inBottomIO( uint16_t y ) const { return y < 2; }
	bool isOuterTop( uint16_t y ) const { return y == num_tile_rows-1; }
	bool isInnerTop( uint16_t y ) const { return y == num_tile_rows-2; }
	bool isOuterBottom( uint16_t y ) const { return y == 0; }
	bool isInnerBottom( uint16_t y ) const { return y == 1; }
	bool inLeftIO( uint16_t x ) const { return x >= num_tile_cols-2; }
	bool inRightIO( uint16_t x ) const { return x < 2; }
	bool isOuterLeft( uint16_t x ) const { return x == num_tile_cols-1; }
	bool isInnerLeft( uint16_t x ) const { return x == num_tile_cols-2; }
	bool isOuterRight( uint16_t x ) const { return x == 0; }
	bool isInnerRight( uint16_t x ) const { return x == 1; }

	bool inLeft( uint16_t x ) const { return x < ((num_tile_cols-1)/2); }
	bool isCenterX( uint16_t x ) const { return x == ((num_tile_cols-1)/2); }
	bool inRight( uint16_t x ) const { return x > ((num_tile_cols-1)/2); }
	bool inBottom( uint16_t y ) const { return y < ((num_tile_rows-1)/2); }
	bool isCenterY( uint16_t y ) const { return y == ((num_tile_rows-1)/2); }
	bool inTop( uint16_t y ) const { return y > ((num_tile_rows-1)/2); }

	bool isRoutingColumn( uint16_t x ) const;

	uint32_t num_clb_slices;
	uint32_t num_bram;
	uint32_t num_dsps;

	uint32_t getTileIndex( int x, int y ) { return ((y * num_tile_cols) + x); }
	uint32_t get_num_minors( const MajorType type );

	// --- processed
	std::vector<const Tile*> tile_coord_lookup; // use TileIndex
	std::vector<ClockDomain> clockdomains;
};

const Spartan6Die& get_spartan6_die( const IdCode idcode );