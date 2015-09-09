
#include "helper.h"
#include "spartan6die.h"

std::string to_string( const IdCode idcode ) {
	switch(idcode){
		case IdCode::XC6SLX4: return "XC6SLX4";
		case IdCode::XC6SLX9: return "XC6SLX9";
		case IdCode::XC6SLX16: return "XC6SLX16";
		case IdCode::XC6SLX25: return "XC6SLX25";
	}
}

IdCode IdCode_from_string( const std::string& str ) {
	if(str == "XC6SLX4") return IdCode::XC6SLX4;
	if(str == "XC6SLX9") return IdCode::XC6SLX9;
	if(str == "XC6SLX16") return IdCode::XC6SLX16;
	if(str == "XC6SLX25") return IdCode::XC6SLX25;

	panic( "Unknown idcode string %s\n", str.c_str() );
	return IdCode::XC6SLX4;
}

std::string to_string( const MajorType mtype ) {
	switch(mtype){
		case MajorType::NULL_TYPE:		return "NULL_TYPE";
		case MajorType::CLB_XM:	return "CLB_XM";
		case MajorType::CLB_XL:	return "CLB_XL";
		case MajorType::CLB_XM_FOLD:	return "CLB_XM_FOLD";
		case MajorType::CLB_XL_FOLD:	return "CLB_XL_FOLD";
		case MajorType::DSP:		return "DSP";
		case MajorType::BRAM:		return "BRAM";
		case MajorType::LTERM:		return "LTERM";
		case MajorType::RTERM:		return "RTERM";
		case MajorType::CENTER:	return "CENTER";
	}
}

MajorType MajorType_from_string( const std::string& str ) {
	if(str == "NULL_TYPE") return MajorType::NULL_TYPE;
	if(str == "CLB_XM") return MajorType::CLB_XM;
	if(str == "CLB_XL") return MajorType::CLB_XL;
	if(str == "CLB_XM_FOLD") return MajorType::CLB_XM_FOLD;
	if(str == "CLB_XL_FOLD") return MajorType::CLB_XL_FOLD;
	if(str == "DSP") return MajorType::DSP;
	if(str == "BRAM") return MajorType::BRAM;
	if(str == "LTERM") return MajorType::LTERM;
	if(str == "RTERM") return MajorType::RTERM;

	panic( "Unknown Major Type string %s\n", str.c_str() );
	return MajorType::NULL_TYPE;
}

std::string to_string( const Spartan6TileTypes type ) {
	switch( type ) {
		case Spartan6TileTypes::BIOB: return "BIOB";
		case Spartan6TileTypes::BIOB_SINGLE: return "BIOB_SINGLE";
		case Spartan6TileTypes::BIOB_SINGLE_ALT: return "BIOB_SINGLE_ALT";
		case Spartan6TileTypes::BIOI_INNER: return "BIOI_INNER";
		case Spartan6TileTypes::BIOI_INNER_UNUSED: return "BIOI_INNER_UNUSED";
		case Spartan6TileTypes::BIOI_OUTER: return "BIOI_OUTER";
		case Spartan6TileTypes::BIOI_OUTER_UNUSED: return "BIOI_OUTER_UNUSED";
		case Spartan6TileTypes::BRAMSITE2: return "BRAMSITE2";
		case Spartan6TileTypes::BRAMSITE2_DUMMY: return "BRAMSITE2_DUMMY";
		case Spartan6TileTypes::BRAM_BOT: return "BRAM_BOT";
		case Spartan6TileTypes::BRAM_BOT_BTERM_L: return "BRAM_BOT_BTERM_L";
		case Spartan6TileTypes::BRAM_BOT_BTERM_R: return "BRAM_BOT_BTERM_R";
		case Spartan6TileTypes::BRAM_HCLK_FEEDTHRU: return "BRAM_HCLK_FEEDTHRU";
		case Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_FOLD: return "BRAM_HCLK_FEEDTHRU_FOLD";
		case Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_INTER: return "BRAM_HCLK_FEEDTHRU_INTER";
		case Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_INTER_FOLD: return "BRAM_HCLK_FEEDTHRU_INTER_FOLD";
		case Spartan6TileTypes::BRAM_INTER_BTERM: return "BRAM_INTER_BTERM";
		case Spartan6TileTypes::BRAM_INTER_TTERM: return "BRAM_INTER_TTERM";
		case Spartan6TileTypes::BRAM_INT_INTERFACE_BOT: return "BRAM_INT_INTERFACE_BOT";
		case Spartan6TileTypes::BRAM_INT_INTERFACE_TOP: return "BRAM_INT_INTERFACE_TOP";
		case Spartan6TileTypes::BRAM_REGH_FEEDTHRU: return "BRAM_REGH_FEEDTHRU";
		case Spartan6TileTypes::BRAM_REGH_FEEDTHRU_INTER: return "BRAM_REGH_FEEDTHRU_INTER";
		case Spartan6TileTypes::BRAM_TOP: return "BRAM_TOP";
		case Spartan6TileTypes::BRAM_TOP_TTERM_L: return "BRAM_TOP_TTERM_L";
		case Spartan6TileTypes::BRAM_TOP_TTERM_R: return "BRAM_TOP_TTERM_R";
		case Spartan6TileTypes::CLB_EMP_BTERM: return "CLB_EMP_BTERM";
		case Spartan6TileTypes::CLB_INT_BTERM: return "CLB_INT_BTERM";
		case Spartan6TileTypes::CLEXL: return "CLEXL";
		case Spartan6TileTypes::CLEXL_DUMMY: return "CLEXL_DUMMY";
		case Spartan6TileTypes::CLEXM: return "CLEXM";
		case Spartan6TileTypes::CLEXM_DUMMY: return "CLEXM_DUMMY";
		case Spartan6TileTypes::CLKC: return "CLKC";
		case Spartan6TileTypes::CMT_CAP: return "CMT_CAP";
		case Spartan6TileTypes::CMT_DCM2_BOT: return "CMT_DCM2_BOT";
		case Spartan6TileTypes::CMT_DCM2_TOP: return "CMT_DCM2_TOP";
		case Spartan6TileTypes::CMT_DCM_BOT: return "CMT_DCM_BOT";
		case Spartan6TileTypes::CMT_DCM_TOP: return "CMT_DCM_TOP";
		case Spartan6TileTypes::CMT_HCLK_BOT25: return "CMT_HCLK_BOT25";
		case Spartan6TileTypes::CMT_PLL1_BOT: return "CMT_PLL1_BOT";
		case Spartan6TileTypes::CMT_PLL2_BOT: return "CMT_PLL2_BOT";
		case Spartan6TileTypes::CMT_PLL2_TOP: return "CMT_PLL2_TOP";
		case Spartan6TileTypes::CMT_PLL3_BOT: return "CMT_PLL3_BOT";
		case Spartan6TileTypes::CMT_PLL3_TOP: return "CMT_PLL3_TOP";
		case Spartan6TileTypes::CMT_PLL_BOT: return "CMT_PLL_BOT";
		case Spartan6TileTypes::CMT_PLL_TOP: return "CMT_PLL_TOP";
		case Spartan6TileTypes::CNR_BR_BTERM: return "CNR_BR_BTERM";
		case Spartan6TileTypes::CNR_TL_LTERM: return "CNR_TL_LTERM";
		case Spartan6TileTypes::CNR_TR_RTERM: return "CNR_TR_RTERM";
		case Spartan6TileTypes::CNR_TR_TTERM: return "CNR_TR_TTERM";
		case Spartan6TileTypes::DSP_BOT_BTERM_L: return "DSP_BOT_BTERM_L";
		case Spartan6TileTypes::DSP_BOT_BTERM_R: return "DSP_BOT_BTERM_R";
		case Spartan6TileTypes::DSP_CLB_HCLK_FEEDTHRU: return "DSP_CLB_HCLK_FEEDTHRU";
		case Spartan6TileTypes::DSP_CLB_HCLK_FEEDTHRU_FOLD: return "DSP_CLB_HCLK_FEEDTHRU_FOLD";
		case Spartan6TileTypes::DSP_EMP_BOT: return "DSP_EMP_BOT";
		case Spartan6TileTypes::DSP_EMP_TEMP: return "DSP_EMP_TEMP";
		case Spartan6TileTypes::DSP_EMP_TOP: return "DSP_EMP_TOP";
		case Spartan6TileTypes::DSP_HCLK_FEEDTHRU_TOP: return "DSP_HCLK_FEEDTHRU_TOP";
		case Spartan6TileTypes::DSP_HCLK_GCLK_FOLD: return "DSP_HCLK_GCLK_FOLD";
		case Spartan6TileTypes::DSP_HCLK_GCLK_NOFOLD: return "DSP_HCLK_GCLK_NOFOLD";
		case Spartan6TileTypes::DSP_INTER_TTERM: return "DSP_INTER_TTERM";
		case Spartan6TileTypes::DSP_INT_BTERM: return "DSP_INT_BTERM";
		case Spartan6TileTypes::DSP_INT_EMP_BOT: return "DSP_INT_EMP_BOT";
		case Spartan6TileTypes::DSP_INT_EMP_TOP: return "DSP_INT_EMP_TOP";
		case Spartan6TileTypes::DSP_INT_HCLK_FEEDTHRU: return "DSP_INT_HCLK_FEEDTHRU";
		case Spartan6TileTypes::DSP_INT_HCLK_FEEDTHRU_FOLD: return "DSP_INT_HCLK_FEEDTHRU_FOLD";
		case Spartan6TileTypes::DSP_INT_TTERM: return "DSP_INT_TTERM";
		case Spartan6TileTypes::DSP_TOP_TTERM_L: return "DSP_TOP_TTERM_L";
		case Spartan6TileTypes::DSP_TOP_TTERM_R: return "DSP_TOP_TTERM_R";
		case Spartan6TileTypes::EMP_LIOB: return "EMP_LIOB";
		case Spartan6TileTypes::EMP_RIOB: return "EMP_RIOB";
		case Spartan6TileTypes::GTPDUAL_BOT: return "GTPDUAL_BOT";
		case Spartan6TileTypes::GTPDUAL_BOT_UNUSED: return "GTPDUAL_BOT_UNUSED";
		case Spartan6TileTypes::GTPDUAL_CLB_FEEDTHRU: return "GTPDUAL_CLB_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_DSP_FEEDTHRU: return "GTPDUAL_DSP_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_INT_FEEDTHRU: return "GTPDUAL_INT_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_LEFT_CLB_FEEDTHRU: return "GTPDUAL_LEFT_CLB_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_LEFT_DSP_FEEDTHRU: return "GTPDUAL_LEFT_DSP_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_LEFT_INT_FEEDTHRU: return "GTPDUAL_LEFT_INT_FEEDTHRU";
		case Spartan6TileTypes::GTPDUAL_TOP: return "GTPDUAL_TOP";
		case Spartan6TileTypes::GTPDUAL_TOP_UNUSED: return "GTPDUAL_TOP_UNUSED";
		case Spartan6TileTypes::HCLK_BRAM_FEEDTHRU: return "HCLK_BRAM_FEEDTHRU";
		case Spartan6TileTypes::HCLK_BRAM_FEEDTHRU_FOLD: return "HCLK_BRAM_FEEDTHRU_FOLD";
		case Spartan6TileTypes::HCLK_CLB_XL_CLE: return "HCLK_CLB_XL_CLE";
		case Spartan6TileTypes::HCLK_CLB_XL_CLE_FOLD: return "HCLK_CLB_XL_CLE_FOLD";
		case Spartan6TileTypes::HCLK_CLB_XL_INT: return "HCLK_CLB_XL_INT";
		case Spartan6TileTypes::HCLK_CLB_XL_INT_FOLD: return "HCLK_CLB_XL_INT_FOLD";
		case Spartan6TileTypes::HCLK_CLB_XM_CLE: return "HCLK_CLB_XM_CLE";
		case Spartan6TileTypes::HCLK_CLB_XM_CLE_FOLD: return "HCLK_CLB_XM_CLE_FOLD";
		case Spartan6TileTypes::HCLK_CLB_XM_INT: return "HCLK_CLB_XM_INT";
		case Spartan6TileTypes::HCLK_CLB_XM_INT_FOLD: return "HCLK_CLB_XM_INT_FOLD";
		case Spartan6TileTypes::HCLK_IOIL_BOT_DN: return "HCLK_IOIL_BOT_DN";
		case Spartan6TileTypes::HCLK_IOIL_BOT_SPLIT: return "HCLK_IOIL_BOT_SPLIT";
		case Spartan6TileTypes::HCLK_IOIL_BOT_UP: return "HCLK_IOIL_BOT_UP";
		case Spartan6TileTypes::HCLK_IOIL_EMP: return "HCLK_IOIL_EMP";
		case Spartan6TileTypes::HCLK_IOIL_INT: return "HCLK_IOIL_INT";
		case Spartan6TileTypes::HCLK_IOIL_INT_FOLD: return "HCLK_IOIL_INT_FOLD";
		case Spartan6TileTypes::HCLK_IOIL_TOP_DN: return "HCLK_IOIL_TOP_DN";
		case Spartan6TileTypes::HCLK_IOIL_TOP_SPLIT: return "HCLK_IOIL_TOP_SPLIT";
		case Spartan6TileTypes::HCLK_IOIL_TOP_UP: return "HCLK_IOIL_TOP_UP";
		case Spartan6TileTypes::HCLK_IOIR_BOT_DN: return "HCLK_IOIR_BOT_DN";
		case Spartan6TileTypes::HCLK_IOIR_BOT_SPLIT: return "HCLK_IOIR_BOT_SPLIT";
		case Spartan6TileTypes::HCLK_IOIR_BOT_UP: return "HCLK_IOIR_BOT_UP";
		case Spartan6TileTypes::HCLK_IOIR_EMP: return "HCLK_IOIR_EMP";
		case Spartan6TileTypes::HCLK_IOIR_INT: return "HCLK_IOIR_INT";
		case Spartan6TileTypes::HCLK_IOIR_INT_FOLD: return "HCLK_IOIR_INT_FOLD";
		case Spartan6TileTypes::HCLK_IOIR_TOP_DN: return "HCLK_IOIR_TOP_DN";
		case Spartan6TileTypes::HCLK_IOIR_TOP_SPLIT: return "HCLK_IOIR_TOP_SPLIT";
		case Spartan6TileTypes::HCLK_IOIR_TOP_UP: return "HCLK_IOIR_TOP_UP";
		case Spartan6TileTypes::HCLK_IOI_LTERM: return "HCLK_IOI_LTERM";
		case Spartan6TileTypes::HCLK_IOI_LTERM_BOT25: return "HCLK_IOI_LTERM_BOT25";
		case Spartan6TileTypes::HCLK_IOI_RTERM: return "HCLK_IOI_RTERM";
		case Spartan6TileTypes::HCLK_IOI_RTERM_BOT25: return "HCLK_IOI_RTERM_BOT25";
		case Spartan6TileTypes::INT: return "INT";
		case Spartan6TileTypes::INT_BRAM: return "INT_BRAM";
		case Spartan6TileTypes::INT_BRAM_BRK: return "INT_BRAM_BRK";
		case Spartan6TileTypes::INT_BRK: return "INT_BRK";
		case Spartan6TileTypes::INT_GCLK: return "INT_GCLK";
		case Spartan6TileTypes::INT_INTERFACE: return "INT_INTERFACE";
		case Spartan6TileTypes::INT_INTERFACE_CARRY: return "INT_INTERFACE_CARRY";
		case Spartan6TileTypes::INT_INTERFACE_IOI: return "INT_INTERFACE_IOI";
		case Spartan6TileTypes::INT_INTERFACE_IOI_DCMBOT: return "INT_INTERFACE_IOI_DCMBOT";
		case Spartan6TileTypes::INT_INTERFACE_LTERM: return "INT_INTERFACE_LTERM";
		case Spartan6TileTypes::INT_INTERFACE_REGC: return "INT_INTERFACE_REGC";
		case Spartan6TileTypes::INT_INTERFACE_RTERM: return "INT_INTERFACE_RTERM";
		case Spartan6TileTypes::INT_LTERM: return "INT_LTERM";
		case Spartan6TileTypes::INT_RTERM: return "INT_RTERM";
		case Spartan6TileTypes::INT_TERM: return "INT_TERM";
		case Spartan6TileTypes::INT_TERM_BRK: return "INT_TERM_BRK";
		case Spartan6TileTypes::IOI_BTERM: return "IOI_BTERM";
		case Spartan6TileTypes::IOI_BTERM_BUFPLL: return "IOI_BTERM_BUFPLL";
		case Spartan6TileTypes::IOI_BTERM_CLB: return "IOI_BTERM_CLB";
		case Spartan6TileTypes::IOI_BTERM_REGB: return "IOI_BTERM_REGB";
		case Spartan6TileTypes::IOI_INT: return "IOI_INT";
		case Spartan6TileTypes::IOI_LTERM: return "IOI_LTERM";
		case Spartan6TileTypes::IOI_LTERM_LOWER_BOT: return "IOI_LTERM_LOWER_BOT";
		case Spartan6TileTypes::IOI_LTERM_LOWER_TOP: return "IOI_LTERM_LOWER_TOP";
		case Spartan6TileTypes::IOI_LTERM_UPPER_BOT: return "IOI_LTERM_UPPER_BOT";
		case Spartan6TileTypes::IOI_LTERM_UPPER_TOP: return "IOI_LTERM_UPPER_TOP";
		case Spartan6TileTypes::IOI_PCI_CE_LEFT: return "IOI_PCI_CE_LEFT";
		case Spartan6TileTypes::IOI_PCI_CE_RIGHT: return "IOI_PCI_CE_RIGHT";
		case Spartan6TileTypes::IOI_RTERM: return "IOI_RTERM";
		case Spartan6TileTypes::IOI_RTERM_LOWER_BOT: return "IOI_RTERM_LOWER_BOT";
		case Spartan6TileTypes::IOI_RTERM_LOWER_TOP: return "IOI_RTERM_LOWER_TOP";
		case Spartan6TileTypes::IOI_RTERM_UPPER_BOT: return "IOI_RTERM_UPPER_BOT";
		case Spartan6TileTypes::IOI_RTERM_UPPER_TOP: return "IOI_RTERM_UPPER_TOP";
		case Spartan6TileTypes::IOI_TTERM: return "IOI_TTERM";
		case Spartan6TileTypes::IOI_TTERM_BUFPLL: return "IOI_TTERM_BUFPLL";
		case Spartan6TileTypes::IOI_TTERM_CLB: return "IOI_TTERM_CLB";
		case Spartan6TileTypes::IOI_TTERM_REGT: return "IOI_TTERM_REGT";
		case Spartan6TileTypes::LIOB: return "LIOB";
		case Spartan6TileTypes::LIOB_PCI: return "LIOB_PCI";
		case Spartan6TileTypes::LIOB_RDY: return "LIOB_RDY";
		case Spartan6TileTypes::LIOI: return "LIOI";
		case Spartan6TileTypes::LIOI_BRK: return "LIOI_BRK";
		case Spartan6TileTypes::LIOI_INT: return "LIOI_INT";
		case Spartan6TileTypes::LIOI_INT_BRK: return "LIOI_INT_BRK";
		case Spartan6TileTypes::LL: return "LL";
		case Spartan6TileTypes::LR_LOWER: return "LR_LOWER";
		case Spartan6TileTypes::LR_UPPER: return "LR_UPPER";
		case Spartan6TileTypes::MACCSITE2: return "MACCSITE2";
		case Spartan6TileTypes::MACCSITE2_DUMMY: return "MACCSITE2_DUMMY";
		case Spartan6TileTypes::MCB_CAP_CLKPN: return "MCB_CAP_CLKPN";
		case Spartan6TileTypes::MCB_CAP_INT: return "MCB_CAP_INT";
		case Spartan6TileTypes::MCB_CAP_INT_BRK: return "MCB_CAP_INT_BRK";
		case Spartan6TileTypes::MCB_CNR_TOP: return "MCB_CNR_TOP";
		case Spartan6TileTypes::MCB_DUMMY: return "MCB_DUMMY";
		case Spartan6TileTypes::MCB_HCLK: return "MCB_HCLK";
		case Spartan6TileTypes::MCB_INT: return "MCB_INT";
		case Spartan6TileTypes::MCB_INT_BOT: return "MCB_INT_BOT";
		case Spartan6TileTypes::MCB_INT_BOT25: return "MCB_INT_BOT25";
		case Spartan6TileTypes::MCB_INT_DQI: return "MCB_INT_DQI";
		case Spartan6TileTypes::MCB_INT_DUMMY: return "MCB_INT_DUMMY";
		case Spartan6TileTypes::MCB_INT_ULDM: return "MCB_INT_ULDM";
		case Spartan6TileTypes::MCB_L: return "MCB_L";
		case Spartan6TileTypes::MCB_L_BOT: return "MCB_L_BOT";
		case Spartan6TileTypes::MCB_MUI0R: return "MCB_MUI0R";
		case Spartan6TileTypes::MCB_MUI0W: return "MCB_MUI0W";
		case Spartan6TileTypes::MCB_MUI1R: return "MCB_MUI1R";
		case Spartan6TileTypes::MCB_MUI1W: return "MCB_MUI1W";
		case Spartan6TileTypes::MCB_MUI2: return "MCB_MUI2";
		case Spartan6TileTypes::MCB_MUI3: return "MCB_MUI3";
		case Spartan6TileTypes::MCB_MUI4: return "MCB_MUI4";
		case Spartan6TileTypes::MCB_MUI5: return "MCB_MUI5";
		case Spartan6TileTypes::MCB_MUI_DUMMY: return "MCB_MUI_DUMMY";
		case Spartan6TileTypes::MCB_REGH: return "MCB_REGH";
		case Spartan6TileTypes::NULL_TILE: return "NULL_TILE";
		case Spartan6TileTypes::PCIE_TOP: return "PCIE_TOP";
		case Spartan6TileTypes::PCIE_TOP_CLB_FEEDTHRU: return "PCIE_TOP_CLB_FEEDTHRU";
		case Spartan6TileTypes::PCIE_TOP_INT_FEEDTHRU: return "PCIE_TOP_INT_FEEDTHRU";
		case Spartan6TileTypes::PCIE_TOP_UNUSED: return "PCIE_TOP_UNUSED";
		case Spartan6TileTypes::RAMB_BOT: return "RAMB_BOT";
		case Spartan6TileTypes::RAMB_BOT_BTERM: return "RAMB_BOT_BTERM";
		case Spartan6TileTypes::RAMB_TOP: return "RAMB_TOP";
		case Spartan6TileTypes::RAMB_TOP_TTERM: return "RAMB_TOP_TTERM";
		case Spartan6TileTypes::REGC_CLE: return "REGC_CLE";
		case Spartan6TileTypes::REGC_INT: return "REGC_INT";
		case Spartan6TileTypes::REGH_BRAM_FEEDTHRU: return "REGH_BRAM_FEEDTHRU";
		case Spartan6TileTypes::REGH_BRAM_FEEDTHRU_L_GCLK: return "REGH_BRAM_FEEDTHRU_L_GCLK";
		case Spartan6TileTypes::REGH_BRAM_FEEDTHRU_R_GCLK: return "REGH_BRAM_FEEDTHRU_R_GCLK";
		case Spartan6TileTypes::REGH_CLEXL_CLE: return "REGH_CLEXL_CLE";
		case Spartan6TileTypes::REGH_CLEXL_INT: return "REGH_CLEXL_INT";
		case Spartan6TileTypes::REGH_CLEXL_INT_CLK: return "REGH_CLEXL_INT_CLK";
		case Spartan6TileTypes::REGH_CLEXM_CLE: return "REGH_CLEXM_CLE";
		case Spartan6TileTypes::REGH_CLEXM_INT: return "REGH_CLEXM_INT";
		case Spartan6TileTypes::REGH_CLEXM_INT_GCLKL: return "REGH_CLEXM_INT_GCLKL";
		case Spartan6TileTypes::REGH_DSP_CLB: return "REGH_DSP_CLB";
		case Spartan6TileTypes::REGH_DSP_INT: return "REGH_DSP_INT";
		case Spartan6TileTypes::REGH_DSP_L: return "REGH_DSP_L";
		case Spartan6TileTypes::REGH_DSP_L_NOCLK: return "REGH_DSP_L_NOCLK";
		case Spartan6TileTypes::REGH_DSP_R: return "REGH_DSP_R";
		case Spartan6TileTypes::REGH_IOI: return "REGH_IOI";
		case Spartan6TileTypes::REGH_IOI_BOT25: return "REGH_IOI_BOT25";
		case Spartan6TileTypes::REGH_IOI_LTERM: return "REGH_IOI_LTERM";
		case Spartan6TileTypes::REGH_IOI_RTERM: return "REGH_IOI_RTERM";
		case Spartan6TileTypes::REGH_LIOI_INT: return "REGH_LIOI_INT";
		case Spartan6TileTypes::REGH_LIOI_INT_BOT25: return "REGH_LIOI_INT_BOT25";
		case Spartan6TileTypes::REGH_RIOI: return "REGH_RIOI";
		case Spartan6TileTypes::REGH_RIOI_BOT25: return "REGH_RIOI_BOT25";
		case Spartan6TileTypes::REGH_RIOI_INT: return "REGH_RIOI_INT";
		case Spartan6TileTypes::REGH_RIOI_INT_BOT25: return "REGH_RIOI_INT_BOT25";
		case Spartan6TileTypes::REG_B: return "REG_B";
		case Spartan6TileTypes::REG_B_BTERM: return "REG_B_BTERM";
		case Spartan6TileTypes::REG_C_CMT: return "REG_C_CMT";
		case Spartan6TileTypes::REG_L: return "REG_L";
		case Spartan6TileTypes::REG_R: return "REG_R";
		case Spartan6TileTypes::REG_T: return "REG_T";
		case Spartan6TileTypes::REG_T_TTERM: return "REG_T_TTERM";
		case Spartan6TileTypes::REG_V: return "REG_V";
		case Spartan6TileTypes::REG_V_BRK: return "REG_V_BRK";
		case Spartan6TileTypes::REG_V_BTERM: return "REG_V_BTERM";
		case Spartan6TileTypes::REG_V_HCLK: return "REG_V_HCLK";
		case Spartan6TileTypes::REG_V_HCLKBUF_BOT: return "REG_V_HCLKBUF_BOT";
		case Spartan6TileTypes::REG_V_HCLKBUF_TOP: return "REG_V_HCLKBUF_TOP";
		case Spartan6TileTypes::REG_V_HCLK_BOT25: return "REG_V_HCLK_BOT25";
		case Spartan6TileTypes::REG_V_MEMB_BOT: return "REG_V_MEMB_BOT";
		case Spartan6TileTypes::REG_V_MEMB_TOP: return "REG_V_MEMB_TOP";
		case Spartan6TileTypes::REG_V_MIDBUF_BOT: return "REG_V_MIDBUF_BOT";
		case Spartan6TileTypes::REG_V_MIDBUF_TOP: return "REG_V_MIDBUF_TOP";
		case Spartan6TileTypes::REG_V_TTERM: return "REG_V_TTERM";
		case Spartan6TileTypes::RIOB: return "RIOB";
		case Spartan6TileTypes::RIOB_PCI: return "RIOB_PCI";
		case Spartan6TileTypes::RIOB_RDY: return "RIOB_RDY";
		case Spartan6TileTypes::RIOI: return "RIOI";
		case Spartan6TileTypes::RIOI_BRK: return "RIOI_BRK";
		case Spartan6TileTypes::TIOB: return "TIOB";
		case Spartan6TileTypes::TIOB_SINGLE: return "TIOB_SINGLE";
		case Spartan6TileTypes::TIOI_INNER: return "TIOI_INNER";
		case Spartan6TileTypes::TIOI_INNER_UNUSED: return "TIOI_INNER_UNUSED";
		case Spartan6TileTypes::TIOI_OUTER: return "TIOI_OUTER";
		case Spartan6TileTypes::UL: return "UL";
		case Spartan6TileTypes::UR_LOWER: return "UR_LOWER";
		case Spartan6TileTypes::UR_UPPER: return "UR_UPPER";
	};
}
Spartan6TileTypes Spartan6TileTypes_from_string( const std::string& str ) {
	if( str == "BIOB") return Spartan6TileTypes::BIOB;
	if( str == "BIOB_SINGLE") return Spartan6TileTypes::BIOB_SINGLE;
	if( str == "BIOB_SINGLE_ALT") return Spartan6TileTypes::BIOB_SINGLE_ALT;
	if( str == "BIOI_INNER") return Spartan6TileTypes::BIOI_INNER;
	if( str == "BIOI_INNER_UNUSED") return Spartan6TileTypes::BIOI_INNER_UNUSED;
	if( str == "BIOI_OUTER") return Spartan6TileTypes::BIOI_OUTER;
	if( str == "BIOI_OUTER_UNUSED") return Spartan6TileTypes::BIOI_OUTER_UNUSED;
	if( str == "BRAMSITE2") return Spartan6TileTypes::BRAMSITE2;
	if( str == "BRAMSITE2_DUMMY") return Spartan6TileTypes::BRAMSITE2_DUMMY;
	if( str == "BRAM_BOT") return Spartan6TileTypes::BRAM_BOT;
	if( str == "BRAM_BOT_BTERM_L") return Spartan6TileTypes::BRAM_BOT_BTERM_L;
	if( str == "BRAM_BOT_BTERM_R") return Spartan6TileTypes::BRAM_BOT_BTERM_R;
	if( str == "BRAM_HCLK_FEEDTHRU") return Spartan6TileTypes::BRAM_HCLK_FEEDTHRU;
	if( str == "BRAM_HCLK_FEEDTHRU_FOLD") return Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_FOLD;
	if( str == "BRAM_HCLK_FEEDTHRU_INTER") return Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_INTER;
	if( str == "BRAM_HCLK_FEEDTHRU_INTER_FOLD") return Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_INTER_FOLD;
	if( str == "BRAM_INTER_BTERM") return Spartan6TileTypes::BRAM_INTER_BTERM;
	if( str == "BRAM_INTER_TTERM") return Spartan6TileTypes::BRAM_INTER_TTERM;
	if( str == "BRAM_INT_INTERFACE_BOT") return Spartan6TileTypes::BRAM_INT_INTERFACE_BOT;
	if( str == "BRAM_INT_INTERFACE_TOP") return Spartan6TileTypes::BRAM_INT_INTERFACE_TOP;
	if( str == "BRAM_REGH_FEEDTHRU") return Spartan6TileTypes::BRAM_REGH_FEEDTHRU;
	if( str == "BRAM_REGH_FEEDTHRU_INTER") return Spartan6TileTypes::BRAM_REGH_FEEDTHRU_INTER;
	if( str == "BRAM_TOP") return Spartan6TileTypes::BRAM_TOP;
	if( str == "BRAM_TOP_TTERM_L") return Spartan6TileTypes::BRAM_TOP_TTERM_L;
	if( str == "BRAM_TOP_TTERM_R") return Spartan6TileTypes::BRAM_TOP_TTERM_R;
	if( str == "CLB_EMP_BTERM") return Spartan6TileTypes::CLB_EMP_BTERM;
	if( str == "CLB_INT_BTERM") return Spartan6TileTypes::CLB_INT_BTERM;
	if( str == "CLEXL") return Spartan6TileTypes::CLEXL;
	if( str == "CLEXL_DUMMY") return Spartan6TileTypes::CLEXL_DUMMY;
	if( str == "CLEXM") return Spartan6TileTypes::CLEXM;
	if( str == "CLEXM_DUMMY") return Spartan6TileTypes::CLEXM_DUMMY;
	if( str == "CLKC") return Spartan6TileTypes::CLKC;
	if( str == "CMT_CAP") return Spartan6TileTypes::CMT_CAP;
	if( str == "CMT_DCM2_BOT") return Spartan6TileTypes::CMT_DCM2_BOT;
	if( str == "CMT_DCM2_TOP") return Spartan6TileTypes::CMT_DCM2_TOP;
	if( str == "CMT_DCM_BOT") return Spartan6TileTypes::CMT_DCM_BOT;
	if( str == "CMT_DCM_TOP") return Spartan6TileTypes::CMT_DCM_TOP;
	if( str == "CMT_HCLK_BOT25") return Spartan6TileTypes::CMT_HCLK_BOT25;
	if( str == "CMT_PLL1_BOT") return Spartan6TileTypes::CMT_PLL1_BOT;
	if( str == "CMT_PLL2_BOT") return Spartan6TileTypes::CMT_PLL2_BOT;
	if( str == "CMT_PLL2_TOP") return Spartan6TileTypes::CMT_PLL2_TOP;
	if( str == "CMT_PLL3_BOT") return Spartan6TileTypes::CMT_PLL3_BOT;
	if( str == "CMT_PLL3_TOP") return Spartan6TileTypes::CMT_PLL3_TOP;
	if( str == "CMT_PLL_BOT") return Spartan6TileTypes::CMT_PLL_BOT;
	if( str == "CMT_PLL_TOP") return Spartan6TileTypes::CMT_PLL_TOP;
	if( str == "CNR_BR_BTERM") return Spartan6TileTypes::CNR_BR_BTERM;
	if( str == "CNR_TL_LTERM") return Spartan6TileTypes::CNR_TL_LTERM;
	if( str == "CNR_TR_RTERM") return Spartan6TileTypes::CNR_TR_RTERM;
	if( str == "CNR_TR_TTERM") return Spartan6TileTypes::CNR_TR_TTERM;
	if( str == "DSP_BOT_BTERM_L") return Spartan6TileTypes::DSP_BOT_BTERM_L;
	if( str == "DSP_BOT_BTERM_R") return Spartan6TileTypes::DSP_BOT_BTERM_R;
	if( str == "DSP_CLB_HCLK_FEEDTHRU") return Spartan6TileTypes::DSP_CLB_HCLK_FEEDTHRU;
	if( str == "DSP_CLB_HCLK_FEEDTHRU_FOLD") return Spartan6TileTypes::DSP_CLB_HCLK_FEEDTHRU_FOLD;
	if( str == "DSP_EMP_BOT") return Spartan6TileTypes::DSP_EMP_BOT;
	if( str == "DSP_EMP_TEMP") return Spartan6TileTypes::DSP_EMP_TEMP;
	if( str == "DSP_EMP_TOP") return Spartan6TileTypes::DSP_EMP_TOP;
	if( str == "DSP_HCLK_FEEDTHRU_TOP") return Spartan6TileTypes::DSP_HCLK_FEEDTHRU_TOP;
	if( str == "DSP_HCLK_GCLK_FOLD") return Spartan6TileTypes::DSP_HCLK_GCLK_FOLD;
	if( str == "DSP_HCLK_GCLK_NOFOLD") return Spartan6TileTypes::DSP_HCLK_GCLK_NOFOLD;
	if( str == "DSP_INTER_TTERM") return Spartan6TileTypes::DSP_INTER_TTERM;
	if( str == "DSP_INT_BTERM") return Spartan6TileTypes::DSP_INT_BTERM;
	if( str == "DSP_INT_EMP_BOT") return Spartan6TileTypes::DSP_INT_EMP_BOT;
	if( str == "DSP_INT_EMP_TOP") return Spartan6TileTypes::DSP_INT_EMP_TOP;
	if( str == "DSP_INT_HCLK_FEEDTHRU") return Spartan6TileTypes::DSP_INT_HCLK_FEEDTHRU;
	if( str == "DSP_INT_HCLK_FEEDTHRU_FOLD") return Spartan6TileTypes::DSP_INT_HCLK_FEEDTHRU_FOLD;
	if( str == "DSP_INT_TTERM") return Spartan6TileTypes::DSP_INT_TTERM;
	if( str == "DSP_TOP_TTERM_L") return Spartan6TileTypes::DSP_TOP_TTERM_L;
	if( str == "DSP_TOP_TTERM_R") return Spartan6TileTypes::DSP_TOP_TTERM_R;
	if( str == "EMP_LIOB") return Spartan6TileTypes::EMP_LIOB;
	if( str == "EMP_RIOB") return Spartan6TileTypes::EMP_RIOB;
	if( str == "GTPDUAL_BOT") return Spartan6TileTypes::GTPDUAL_BOT;
	if( str == "GTPDUAL_BOT_UNUSED") return Spartan6TileTypes::GTPDUAL_BOT_UNUSED;
	if( str == "GTPDUAL_CLB_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_CLB_FEEDTHRU;
	if( str == "GTPDUAL_DSP_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_DSP_FEEDTHRU;
	if( str == "GTPDUAL_INT_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_INT_FEEDTHRU;
	if( str == "GTPDUAL_LEFT_CLB_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_LEFT_CLB_FEEDTHRU;
	if( str == "GTPDUAL_LEFT_DSP_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_LEFT_DSP_FEEDTHRU;
	if( str == "GTPDUAL_LEFT_INT_FEEDTHRU") return Spartan6TileTypes::GTPDUAL_LEFT_INT_FEEDTHRU;
	if( str == "GTPDUAL_TOP") return Spartan6TileTypes::GTPDUAL_TOP;
	if( str == "GTPDUAL_TOP_UNUSED") return Spartan6TileTypes::GTPDUAL_TOP_UNUSED;
	if( str == "HCLK_BRAM_FEEDTHRU") return Spartan6TileTypes::HCLK_BRAM_FEEDTHRU;
	if( str == "HCLK_BRAM_FEEDTHRU_FOLD") return Spartan6TileTypes::HCLK_BRAM_FEEDTHRU_FOLD;
	if( str == "HCLK_CLB_XL_CLE") return Spartan6TileTypes::HCLK_CLB_XL_CLE;
	if( str == "HCLK_CLB_XL_CLE_FOLD") return Spartan6TileTypes::HCLK_CLB_XL_CLE_FOLD;
	if( str == "HCLK_CLB_XL_INT") return Spartan6TileTypes::HCLK_CLB_XL_INT;
	if( str == "HCLK_CLB_XL_INT_FOLD") return Spartan6TileTypes::HCLK_CLB_XL_INT_FOLD;
	if( str == "HCLK_CLB_XM_CLE") return Spartan6TileTypes::HCLK_CLB_XM_CLE;
	if( str == "HCLK_CLB_XM_CLE_FOLD") return Spartan6TileTypes::HCLK_CLB_XM_CLE_FOLD;
	if( str == "HCLK_CLB_XM_INT") return Spartan6TileTypes::HCLK_CLB_XM_INT;
	if( str == "HCLK_CLB_XM_INT_FOLD") return Spartan6TileTypes::HCLK_CLB_XM_INT_FOLD;
	if( str == "HCLK_IOIL_BOT_DN") return Spartan6TileTypes::HCLK_IOIL_BOT_DN;
	if( str == "HCLK_IOIL_BOT_SPLIT") return Spartan6TileTypes::HCLK_IOIL_BOT_SPLIT;
	if( str == "HCLK_IOIL_BOT_UP") return Spartan6TileTypes::HCLK_IOIL_BOT_UP;
	if( str == "HCLK_IOIL_EMP") return Spartan6TileTypes::HCLK_IOIL_EMP;
	if( str == "HCLK_IOIL_INT") return Spartan6TileTypes::HCLK_IOIL_INT;
	if( str == "HCLK_IOIL_INT_FOLD") return Spartan6TileTypes::HCLK_IOIL_INT_FOLD;
	if( str == "HCLK_IOIL_TOP_DN") return Spartan6TileTypes::HCLK_IOIL_TOP_DN;
	if( str == "HCLK_IOIL_TOP_SPLIT") return Spartan6TileTypes::HCLK_IOIL_TOP_SPLIT;
	if( str == "HCLK_IOIL_TOP_UP") return Spartan6TileTypes::HCLK_IOIL_TOP_UP;
	if( str == "HCLK_IOIR_BOT_DN") return Spartan6TileTypes::HCLK_IOIR_BOT_DN;
	if( str == "HCLK_IOIR_BOT_SPLIT") return Spartan6TileTypes::HCLK_IOIR_BOT_SPLIT;
	if( str == "HCLK_IOIR_BOT_UP") return Spartan6TileTypes::HCLK_IOIR_BOT_UP;
	if( str == "HCLK_IOIR_EMP") return Spartan6TileTypes::HCLK_IOIR_EMP;
	if( str == "HCLK_IOIR_INT") return Spartan6TileTypes::HCLK_IOIR_INT;
	if( str == "HCLK_IOIR_INT_FOLD") return Spartan6TileTypes::HCLK_IOIR_INT_FOLD;
	if( str == "HCLK_IOIR_TOP_DN") return Spartan6TileTypes::HCLK_IOIR_TOP_DN;
	if( str == "HCLK_IOIR_TOP_SPLIT") return Spartan6TileTypes::HCLK_IOIR_TOP_SPLIT;
	if( str == "HCLK_IOIR_TOP_UP") return Spartan6TileTypes::HCLK_IOIR_TOP_UP;
	if( str == "HCLK_IOI_LTERM") return Spartan6TileTypes::HCLK_IOI_LTERM;
	if( str == "HCLK_IOI_LTERM_BOT25") return Spartan6TileTypes::HCLK_IOI_LTERM_BOT25;
	if( str == "HCLK_IOI_RTERM") return Spartan6TileTypes::HCLK_IOI_RTERM;
	if( str == "HCLK_IOI_RTERM_BOT25") return Spartan6TileTypes::HCLK_IOI_RTERM_BOT25;
	if( str == "INT") return Spartan6TileTypes::INT;
	if( str == "INT_BRAM") return Spartan6TileTypes::INT_BRAM;
	if( str == "INT_BRAM_BRK") return Spartan6TileTypes::INT_BRAM_BRK;
	if( str == "INT_BRK") return Spartan6TileTypes::INT_BRK;
	if( str == "INT_GCLK") return Spartan6TileTypes::INT_GCLK;
	if( str == "INT_INTERFACE") return Spartan6TileTypes::INT_INTERFACE;
	if( str == "INT_INTERFACE_CARRY") return Spartan6TileTypes::INT_INTERFACE_CARRY;
	if( str == "INT_INTERFACE_IOI") return Spartan6TileTypes::INT_INTERFACE_IOI;
	if( str == "INT_INTERFACE_IOI_DCMBOT") return Spartan6TileTypes::INT_INTERFACE_IOI_DCMBOT;
	if( str == "INT_INTERFACE_LTERM") return Spartan6TileTypes::INT_INTERFACE_LTERM;
	if( str == "INT_INTERFACE_REGC") return Spartan6TileTypes::INT_INTERFACE_REGC;
	if( str == "INT_INTERFACE_RTERM") return Spartan6TileTypes::INT_INTERFACE_RTERM;
	if( str == "INT_LTERM") return Spartan6TileTypes::INT_LTERM;
	if( str == "INT_RTERM") return Spartan6TileTypes::INT_RTERM;
	if( str == "INT_TERM") return Spartan6TileTypes::INT_TERM;
	if( str == "INT_TERM_BRK") return Spartan6TileTypes::INT_TERM_BRK;
	if( str == "IOI_BTERM") return Spartan6TileTypes::IOI_BTERM;
	if( str == "IOI_BTERM_BUFPLL") return Spartan6TileTypes::IOI_BTERM_BUFPLL;
	if( str == "IOI_BTERM_CLB") return Spartan6TileTypes::IOI_BTERM_CLB;
	if( str == "IOI_BTERM_REGB") return Spartan6TileTypes::IOI_BTERM_REGB;
	if( str == "IOI_INT") return Spartan6TileTypes::IOI_INT;
	if( str == "IOI_LTERM") return Spartan6TileTypes::IOI_LTERM;
	if( str == "IOI_LTERM_LOWER_BOT") return Spartan6TileTypes::IOI_LTERM_LOWER_BOT;
	if( str == "IOI_LTERM_LOWER_TOP") return Spartan6TileTypes::IOI_LTERM_LOWER_TOP;
	if( str == "IOI_LTERM_UPPER_BOT") return Spartan6TileTypes::IOI_LTERM_UPPER_BOT;
	if( str == "IOI_LTERM_UPPER_TOP") return Spartan6TileTypes::IOI_LTERM_UPPER_TOP;
	if( str == "IOI_PCI_CE_LEFT") return Spartan6TileTypes::IOI_PCI_CE_LEFT;
	if( str == "IOI_PCI_CE_RIGHT") return Spartan6TileTypes::IOI_PCI_CE_RIGHT;
	if( str == "IOI_RTERM") return Spartan6TileTypes::IOI_RTERM;
	if( str == "IOI_RTERM_LOWER_BOT") return Spartan6TileTypes::IOI_RTERM_LOWER_BOT;
	if( str == "IOI_RTERM_LOWER_TOP") return Spartan6TileTypes::IOI_RTERM_LOWER_TOP;
	if( str == "IOI_RTERM_UPPER_BOT") return Spartan6TileTypes::IOI_RTERM_UPPER_BOT;
	if( str == "IOI_RTERM_UPPER_TOP") return Spartan6TileTypes::IOI_RTERM_UPPER_TOP;
	if( str == "IOI_TTERM") return Spartan6TileTypes::IOI_TTERM;
	if( str == "IOI_TTERM_BUFPLL") return Spartan6TileTypes::IOI_TTERM_BUFPLL;
	if( str == "IOI_TTERM_CLB") return Spartan6TileTypes::IOI_TTERM_CLB;
	if( str == "IOI_TTERM_REGT") return Spartan6TileTypes::IOI_TTERM_REGT;
	if( str == "LIOB") return Spartan6TileTypes::LIOB;
	if( str == "LIOB_PCI") return Spartan6TileTypes::LIOB_PCI;
	if( str == "LIOB_RDY") return Spartan6TileTypes::LIOB_RDY;
	if( str == "LIOI") return Spartan6TileTypes::LIOI;
	if( str == "LIOI_BRK") return Spartan6TileTypes::LIOI_BRK;
	if( str == "LIOI_INT") return Spartan6TileTypes::LIOI_INT;
	if( str == "LIOI_INT_BRK") return Spartan6TileTypes::LIOI_INT_BRK;
	if( str == "LL") return Spartan6TileTypes::LL;
	if( str == "LR_LOWER") return Spartan6TileTypes::LR_LOWER;
	if( str == "LR_UPPER") return Spartan6TileTypes::LR_UPPER;
	if( str == "MACCSITE2") return Spartan6TileTypes::MACCSITE2;
	if( str == "MACCSITE2_DUMMY") return Spartan6TileTypes::MACCSITE2_DUMMY;
	if( str == "MCB_CAP_CLKPN") return Spartan6TileTypes::MCB_CAP_CLKPN;
	if( str == "MCB_CAP_INT") return Spartan6TileTypes::MCB_CAP_INT;
	if( str == "MCB_CAP_INT_BRK") return Spartan6TileTypes::MCB_CAP_INT_BRK;
	if( str == "MCB_CNR_TOP") return Spartan6TileTypes::MCB_CNR_TOP;
	if( str == "MCB_DUMMY") return Spartan6TileTypes::MCB_DUMMY;
	if( str == "MCB_HCLK") return Spartan6TileTypes::MCB_HCLK;
	if( str == "MCB_INT") return Spartan6TileTypes::MCB_INT;
	if( str == "MCB_INT_BOT") return Spartan6TileTypes::MCB_INT_BOT;
	if( str == "MCB_INT_BOT25") return Spartan6TileTypes::MCB_INT_BOT25;
	if( str == "MCB_INT_DQI") return Spartan6TileTypes::MCB_INT_DQI;
	if( str == "MCB_INT_DUMMY") return Spartan6TileTypes::MCB_INT_DUMMY;
	if( str == "MCB_INT_ULDM") return Spartan6TileTypes::MCB_INT_ULDM;
	if( str == "MCB_L") return Spartan6TileTypes::MCB_L;
	if( str == "MCB_L_BOT") return Spartan6TileTypes::MCB_L_BOT;
	if( str == "MCB_MUI0R") return Spartan6TileTypes::MCB_MUI0R;
	if( str == "MCB_MUI0W") return Spartan6TileTypes::MCB_MUI0W;
	if( str == "MCB_MUI1R") return Spartan6TileTypes::MCB_MUI1R;
	if( str == "MCB_MUI1W") return Spartan6TileTypes::MCB_MUI1W;
	if( str == "MCB_MUI2") return Spartan6TileTypes::MCB_MUI2;
	if( str == "MCB_MUI3") return Spartan6TileTypes::MCB_MUI3;
	if( str == "MCB_MUI4") return Spartan6TileTypes::MCB_MUI4;
	if( str == "MCB_MUI5") return Spartan6TileTypes::MCB_MUI5;
	if( str == "MCB_MUI_DUMMY") return Spartan6TileTypes::MCB_MUI_DUMMY;
	if( str == "MCB_REGH") return Spartan6TileTypes::MCB_REGH;
	if( str == "NULL_TILE" ) return Spartan6TileTypes::NULL_TILE;
	if( str == "PCIE_TOP") return Spartan6TileTypes::PCIE_TOP;
	if( str == "PCIE_TOP_CLB_FEEDTHRU") return Spartan6TileTypes::PCIE_TOP_CLB_FEEDTHRU;
	if( str == "PCIE_TOP_INT_FEEDTHRU") return Spartan6TileTypes::PCIE_TOP_INT_FEEDTHRU;
	if( str == "PCIE_TOP_UNUSED") return Spartan6TileTypes::PCIE_TOP_UNUSED;
	if( str == "RAMB_BOT") return Spartan6TileTypes::RAMB_BOT;
	if( str == "RAMB_BOT_BTERM") return Spartan6TileTypes::RAMB_BOT_BTERM;
	if( str == "RAMB_TOP") return Spartan6TileTypes::RAMB_TOP;
	if( str == "RAMB_TOP_TTERM") return Spartan6TileTypes::RAMB_TOP_TTERM;
	if( str == "REGC_CLE") return Spartan6TileTypes::REGC_CLE;
	if( str == "REGC_INT") return Spartan6TileTypes::REGC_INT;
	if( str == "REGH_BRAM_FEEDTHRU") return Spartan6TileTypes::REGH_BRAM_FEEDTHRU;
	if( str == "REGH_BRAM_FEEDTHRU_L_GCLK") return Spartan6TileTypes::REGH_BRAM_FEEDTHRU_L_GCLK;
	if( str == "REGH_BRAM_FEEDTHRU_R_GCLK") return Spartan6TileTypes::REGH_BRAM_FEEDTHRU_R_GCLK;
	if( str == "REGH_CLEXL_CLE") return Spartan6TileTypes::REGH_CLEXL_CLE;
	if( str == "REGH_CLEXL_INT") return Spartan6TileTypes::REGH_CLEXL_INT;
	if( str == "REGH_CLEXL_INT_CLK") return Spartan6TileTypes::REGH_CLEXL_INT_CLK;
	if( str == "REGH_CLEXM_CLE") return Spartan6TileTypes::REGH_CLEXM_CLE;
	if( str == "REGH_CLEXM_INT") return Spartan6TileTypes::REGH_CLEXM_INT;
	if( str == "REGH_CLEXM_INT_GCLKL") return Spartan6TileTypes::REGH_CLEXM_INT_GCLKL;
	if( str == "REGH_DSP_CLB") return Spartan6TileTypes::REGH_DSP_CLB;
	if( str == "REGH_DSP_INT") return Spartan6TileTypes::REGH_DSP_INT;
	if( str == "REGH_DSP_L") return Spartan6TileTypes::REGH_DSP_L;
	if( str == "REGH_DSP_L_NOCLK") return Spartan6TileTypes::REGH_DSP_L_NOCLK;
	if( str == "REGH_DSP_R") return Spartan6TileTypes::REGH_DSP_R;
	if( str == "REGH_IOI") return Spartan6TileTypes::REGH_IOI;
	if( str == "REGH_IOI_BOT25") return Spartan6TileTypes::REGH_IOI_BOT25;
	if( str == "REGH_IOI_LTERM") return Spartan6TileTypes::REGH_IOI_LTERM;
	if( str == "REGH_IOI_RTERM") return Spartan6TileTypes::REGH_IOI_RTERM;
	if( str == "REGH_LIOI_INT") return Spartan6TileTypes::REGH_LIOI_INT;
	if( str == "REGH_LIOI_INT_BOT25") return Spartan6TileTypes::REGH_LIOI_INT_BOT25;
	if( str == "REGH_RIOI") return Spartan6TileTypes::REGH_RIOI;
	if( str == "REGH_RIOI_BOT25") return Spartan6TileTypes::REGH_RIOI_BOT25;
	if( str == "REGH_RIOI_INT") return Spartan6TileTypes::REGH_RIOI_INT;
	if( str == "REGH_RIOI_INT_BOT25") return Spartan6TileTypes::REGH_RIOI_INT_BOT25;
	if( str == "REG_B") return Spartan6TileTypes::REG_B;
	if( str == "REG_B_BTERM") return Spartan6TileTypes::REG_B_BTERM;
	if( str == "REG_C_CMT") return Spartan6TileTypes::REG_C_CMT;
	if( str == "REG_L") return Spartan6TileTypes::REG_L;
	if( str == "REG_R") return Spartan6TileTypes::REG_R;
	if( str == "REG_T") return Spartan6TileTypes::REG_T;
	if( str == "REG_T_TTERM") return Spartan6TileTypes::REG_T_TTERM;
	if( str == "REG_V") return Spartan6TileTypes::REG_V;
	if( str == "REG_V_BRK") return Spartan6TileTypes::REG_V_BRK;
	if( str == "REG_V_BTERM") return Spartan6TileTypes::REG_V_BTERM;
	if( str == "REG_V_HCLK") return Spartan6TileTypes::REG_V_HCLK;
	if( str == "REG_V_HCLKBUF_BOT") return Spartan6TileTypes::REG_V_HCLKBUF_BOT;
	if( str == "REG_V_HCLKBUF_TOP") return Spartan6TileTypes::REG_V_HCLKBUF_TOP;
	if( str == "REG_V_HCLK_BOT25") return Spartan6TileTypes::REG_V_HCLK_BOT25;
	if( str == "REG_V_MEMB_BOT") return Spartan6TileTypes::REG_V_MEMB_BOT;
	if( str == "REG_V_MEMB_TOP") return Spartan6TileTypes::REG_V_MEMB_TOP;
	if( str == "REG_V_MIDBUF_BOT") return Spartan6TileTypes::REG_V_MIDBUF_BOT;
	if( str == "REG_V_MIDBUF_TOP") return Spartan6TileTypes::REG_V_MIDBUF_TOP;
	if( str == "REG_V_TTERM") return Spartan6TileTypes::REG_V_TTERM;
	if( str == "RIOB") return Spartan6TileTypes::RIOB;
	if( str == "RIOB_PCI") return Spartan6TileTypes::RIOB_PCI;
	if( str == "RIOB_RDY") return Spartan6TileTypes::RIOB_RDY;
	if( str == "RIOI") return Spartan6TileTypes::RIOI;
	if( str == "RIOI_BRK") return Spartan6TileTypes::RIOI_BRK;
	if( str == "TIOB") return Spartan6TileTypes::TIOB;
	if( str == "TIOB_SINGLE") return Spartan6TileTypes::TIOB_SINGLE;
	if( str == "TIOI_INNER") return Spartan6TileTypes::TIOI_INNER;
	if( str == "TIOI_INNER_UNUSED") return Spartan6TileTypes::TIOI_INNER_UNUSED;
	if( str == "TIOI_OUTER") return Spartan6TileTypes::TIOI_OUTER;
	if( str == "UL") return Spartan6TileTypes::UL;
	if( str == "UR_LOWER") return Spartan6TileTypes::UR_LOWER;
	if( str == "UR_UPPER") return Spartan6TileTypes::UR_UPPER;
	assert( false ); return Spartan6TileTypes::BIOB;
}


// from xilinx employee on forums
//Frame Length of Core - CLB etc. = (16+1)*4 = 65  16-bit words
//Frame Length of BRAM = 18 bits
//Frame Length of IOB = # of IOB * 4 16-bit words
// So, the address register (FAR), as well as in Virtex.-5 contains a field to address different clock regions, 
// another field to specify the CLB row (major address) and another one to specify the number of specific frames within a CLB row (minor address) 
// to fully decode the address of regular logic elements within the FPGAarchitecture.

// die data is obtained from fpgatools, torc, xilix docsuments and some sherlock holmes
// Xilinx has multiple coordinate systems which makes understanding the names and number a bit confusing.

// Tiles coodinates is absolute but rarely seen outside NULL tiles, 
// Physical coordinates are in actual blocks in the hardware, each block is made up of 17x11 tiles
// 		16x10 normal tiles and a clk tile in each direction spliting the normal tiles into 2 (i.e 8,CLK,8 )
// therefore Tile Coord = Physical Coord * <17,11>
// Physical Y is also known simply as Rows and also (incorrectly?) clock domains (each Row is actually 2 domains?),

// To map a major address to a tile requires knowing what the type of major is (variable cols per major type)
// A physical row is split into 2 by a center clk column (which is why each p row has dual clock domains)
// Each physical col is split into 2 by a center clk row
/*
Spartan6Die XC6SLX9die =
{
	73, 45, // tile row and cols
	4, 18, 	// physical row and col row = tile_row -5 / 17   		5=2t+1c+2b 17=8+c+8
			// 						col = tile_col -(10-1) / 2    	10=5l+1c+5r 
	1430, 	// num_clb_slices
	32, 	// num_bram
	16,		// num_dsp
	576, 	// num_bram_in_KB num_bram * 18
};

Spartan6Die XC6SLX25die =
{
	90, 81, // tile row and cols
	5, 36, 	// physical row and col row = tile_row -5 / 17   		5=2t+1c+2b 17=8+c+8
			// 						col = tile_col -(10-1) / 2    	10=5l+1c+5r 
	3758,	// num_clb_slices
	52, 	// num_bram
	38,		// num_dsp
	936, 	// num_bram_in_KB num_bram * 18
};
*/

// I think minors per major type are constant for all Spartan 6
uint32_t Spartan6Die::get_num_minors( const MajorType type )
{
	switch( type ) {
		case MajorType::NULL_TYPE:		return 4;
		case MajorType::CLB_XM_FOLD:
		case MajorType::CLB_XM:		return 31;
		case MajorType::CLB_XL_FOLD:
		case MajorType::CLB_XL:		return 30;
		case MajorType::DSP:		return 24;
		case MajorType::BRAM:		return 25;
		case MajorType::LTERM:		return 30;
		case MajorType::RTERM:		return 30;
		case MajorType::CENTER:		return 1;	//?
	}

}

#include "autogen/xc6slx9.h"
#include "autogen/xc6slx25.h"

const Spartan6Die& get_spartan6_die( const IdCode idcode )
{
	Spartan6Die* die;
	debug( "getting die for %s\n", to_string(idcode).c_str() );

	switch( idcode )
	{
		case IdCode::XC6SLX9: die = &s_xc6slx9die; break;
		case IdCode::XC6SLX25: die = &s_xc6slx25die; break;
		default: panic( "No die information for %s\n", to_string(idcode).c_str() );
	}

	die->process();
	return *die;
}

void Spartan6Die::process() {
	if( been_processed == true )
		return;
	been_processed = true;


	tile_coord_lookup.resize( tiles.size()+1 );

	// create 2D tile coordiante look-up table
	for( auto& ti : tiles ) {
		tile_coord_lookup[ getTileIndex(ti.x(), ti.y()) ] = &ti;
	}

	verbose( "tile_coord_lookup table build for %i tiles\n", (int)tiles.size() );

	// clockdomains go across the die
	// Each clockdoman can have a diffrent set of majors!
	// 	  Wolf never found this as the sx9 part was symmetrical, sx25 isn't

	clockdomains.resize( num_physical_rows );

	// tile row coordinates
	// scan row 10 (skip 2 row for bottom and half a row of clb to get to the hclk)
	// each physical row is 17 tile rows
	// plus have to adjust in second half for center row (1 rows of a REGH )
	//      the clock row before the center is slightly different in ints tile types


	// scan wolf style major columns from actual tile columns
	// Logic are 2 INT + XM | XL
	// BRAM = 3
	// DSP = 3
	// LEFT = 5
	// RIGHT = 5
	// Scan from middle of first row (tile row 10)	
	int pr = 0;
	for( auto& cd : clockdomains ) {
		auto& row_major = cd.majors;

		int y = 10 + (17 * pr) + ((pr < (num_physical_rows+1)/2) ? 0 : 1);
		cd.top_tile_row = y - 10;

		int x = 0;
		// first 5 should have HCLK_IOI_LTERM
		bool found_lterm = false;
		for( x = 0;x < 5; x++ ) {
			const auto tile = tile_coord_lookup[ getTileIndex(x,y) ];
			verbose( "<%i,%i> tile type %s\n", tile->tile_col, tile->tile_row, to_string(tile->type).c_str() );
			assert( tile->tile_col == x && tile->tile_row == y);
			if( tile->type == Spartan6TileTypes::HCLK_IOI_LTERM || 
				tile->type == Spartan6TileTypes::HCLK_IOI_LTERM_BOT25 // this only happens on the row before the center marker
				) {
				found_lterm = true;
				break;
			}
		}
		assert( found_lterm == true );
		row_major.push_back( MajorType::LTERM );
		x = 5;

		bool found_rterm = false;
		// scan until we hit right
		while( (x < num_tile_rows) &&  (found_rterm == false) ) { 

			const auto tile = tile_coord_lookup[ getTileIndex(x,y) ];
			verbose( "<%i,%i> tile type %s\n", tile->tile_col, tile->tile_row, to_string(tile->type).c_str() );
			switch( tile->type ) {
				case Spartan6TileTypes::HCLK_IOIR_INT:
				case Spartan6TileTypes::HCLK_IOI_RTERM:
					row_major.push_back( MajorType::RTERM );
					found_rterm = true;
					break;
				case Spartan6TileTypes::HCLK_CLB_XM_INT: // Spartan 6 always have switch matrix before logic
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::HCLK_CLB_XM_CLE );
					row_major.push_back( MajorType::CLB_XM);
					x+=2; // CLB_XM are two rows INT + CLE
				break;
				case Spartan6TileTypes::HCLK_CLB_XL_INT: // Spartan 6 always have switch matrix before logic
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::HCLK_CLB_XL_CLE );
					row_major.push_back( MajorType::CLB_XL);
					x+=2; // CLB_XL are two rows INT + CLE
				break;
				case Spartan6TileTypes::HCLK_CLB_XM_CLE_FOLD: // folds seem to have the switch matrix after?
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::HCLK_CLB_XM_INT );
					row_major.push_back( MajorType::CLB_XM_FOLD); 
					x+=2; // CLB_XM_FOLD are two rows CLE_FOLD INT
					break;
				case Spartan6TileTypes::HCLK_CLB_XL_CLE_FOLD: // folds seem to have the switch matrix after?
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::HCLK_CLB_XL_INT );
					row_major.push_back( MajorType::CLB_XL_FOLD);
					x+=2; // CLB_XL_FOLD are two rows CLE_FOLD + INT
				break;
				case Spartan6TileTypes::BRAM_HCLK_FEEDTHRU:
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::BRAM_HCLK_FEEDTHRU_INTER );
					assert( tile_coord_lookup[ getTileIndex(x+2,y) ]->type == Spartan6TileTypes::HCLK_BRAM_FEEDTHRU );
					row_major.push_back( MajorType::BRAM);
					x+=3; // BRAM are three rows
				break;
				case Spartan6TileTypes::DSP_INT_HCLK_FEEDTHRU:
					assert( tile_coord_lookup[ getTileIndex(x+1,y) ]->type == Spartan6TileTypes::DSP_CLB_HCLK_FEEDTHRU );
					assert( tile_coord_lookup[ getTileIndex(x+2,y) ]->type == Spartan6TileTypes::DSP_HCLK_FEEDTHRU_TOP );
					row_major.push_back( MajorType::DSP);
					x+=3; // DSP are three rows
				break;
				case Spartan6TileTypes::CMT_HCLK_BOT25: // TODO what is this?
				case Spartan6TileTypes::NULL_TILE:
					row_major.push_back( MajorType::NULL_TYPE );
					x+=1;
				break;

				case Spartan6TileTypes::REG_V_HCLK_BOT25:
				case Spartan6TileTypes::REG_V_HCLK:
					row_major.push_back( MajorType::CENTER );				
					x+=1;
				break;
				case Spartan6TileTypes::HCLK_CLB_XM_CLE: 
					// this should always follow an XM_INT but in one case it doesn't, this makes no sense as all CLE
					// need an switch matrix, but apparently if the torc DB is right, there is one that doesn't.. hmmm
					// for now ignore it but odd very odd... its after a fold which might mean something?
					// problem is will it screw up minor counting...
					x+=1;		
				break;
				default:
					x+=1;
					error( "Unknown tile type in major scan %s\n", to_string(tile->type).c_str() );
			}
		}

		// interesting using torc db seems that center is a 2 minor, wheras wolf thought it was 4
		// the other 2 are showing up as a standard logic XL which also is more symmetrical. so
		// I think torc db is right

		debug( "Physical row %i Majors ", pr );
		uint16_t& total_minors = cd.frame_count;
		total_minors = 0;
		uint16_t majorCount = 0;
		for( auto ma : row_major ) {
			debug( "%s (%i), ", to_string(ma).c_str(), get_num_minors(ma) );
			if( ma == MajorType::CENTER ) {
				cd.center_major_index = majorCount;
			}
			if( ma == MajorType::RTERM ) {
				cd.right_major_index = majorCount;				
			}
			total_minors += get_num_minors(ma);
			majorCount++;
		}

		debug ("\n");
		debug("minors per row %i\n", total_minors );


		pr++; // next physical row
	}


}

bool Spartan6Die::isRoutingColumn( uint16_t x ) const {

}
