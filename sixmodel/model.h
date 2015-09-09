
#include "spartan6die.h"
struct model
{
	const class Spartan6Die* die;
	const struct xc6_pkg_info *pkg;

	int x_width, y_height;
	int center_x;
	int center_y;
	
	// Left and right gclk separators will be located on
	// the device column (+1 or +2) of the logic or dsp/macc
	// column as indicated in the chip's cfg_columns with a 'g'.
	int left_gclk_sep_x, right_gclk_sep_x;

	// x_major is an array of column indices for each x coordinate,
	// starting with column 1 for the left side, and incrementing
	// through the configuration columns. This corresponds to the
	// 'majors' in the bitstream.
	int x_major[512];

};