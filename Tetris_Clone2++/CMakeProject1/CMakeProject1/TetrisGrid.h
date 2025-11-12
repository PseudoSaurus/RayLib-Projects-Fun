#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class Grid
{
public:
	Grid();
	void Initialization();
	void Display();
	int grid[20][10];
	void Draw();
	bool IsBlockOffBounds(int row, int column);
	bool IsCellEmpty(int row, int column);
	int ClearFullRows();


private:
	vector<Color> colors;
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowsDown();
	int numRows,
		numCols,
		cellSize;
};
