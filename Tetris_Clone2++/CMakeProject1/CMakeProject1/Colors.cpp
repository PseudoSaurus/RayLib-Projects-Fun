#include "Colors.h"
using namespace std;

const Color darkGray = { 44, 44, 127, 255 },
			blue = { 13, 64, 216, 255 },
			cyan = { 21, 204, 209, 255 },
			green = { 47, 230, 23, 255 },
			orange = { 226, 116, 17, 255 },
			purple = { 166, 0, 247, 255 },
			red = { 232, 18, 18, 255 },
			yellow = { 44, 44, 127, 255 },
			darkblue = { 44,44,127,255 },
			lightblue = { 59,85,162,255 };

vector<Color> GetCellColors()
{
	return { darkGray, blue, cyan, green, orange, purple, red, yellow, darkblue, lightblue };
}