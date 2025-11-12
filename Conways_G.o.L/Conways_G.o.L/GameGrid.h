#pragma once
#include <vector>
using namespace std;

class LifeGrid 
{
public:
	LifeGrid(int width, int height, int cellSize)
		: rows(height / cellSize), cols(width / cellSize), cellSize(cellSize), CELL_life(rows, vector<int>(cols, 0)) {
	};
	void DrawGrid();
	void SetCellValue(int row, int col, int value);
	int GetValue(int row, int column);
	int GetRows() { return rows };
	int GetColumns() {return cols};
	bool IsBounded(int row, int column);
	void FillRand();
	void ClearGrid();
	void ToggleCell(int row, int col);
private:
	int rows;
	int cols;
	int cellSize;

	vector<vector<int>> CELL_life;

};

