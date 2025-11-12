#include <raylib.h>
#include "GameGrid.h"


void LifeGrid::DrawGrid()
{
	for (int row = 0; row < rows; row++)
	{
		for (int columns = 0; columns < cols; columns++)
		{
			Color color = CELL_life[row][columns] ? Color(0, 255, 0, 255) : Color(55, 55, 55, 255);
			DrawRecrangle(columns * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
		}
	}
}

void LifeGrid::SetCellValue(int row, int col, int value)
{
	if (IsBounded(row, col))
		CELL_life[row][col] = value;
}

int LifeGrid::GetValue(int row, int column)
{
	if (IsBounded(row, column))
		return CELL_life[row][column];

	return 0;
}

bool LifeGrid::IsBounded(int row, int column)
{
	if (row >= 0 && row < rows && column >= 0 && column < cols)
		return true;

	return false;
}

void LifeGrid::FillRand()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < cols; column++)
		{
			int randNum = GetRandomValue(0, 4);

			CELL_life[row][column] = (randNum < 3) ? 1 : 0;
		}
	}
	
}

void LifeGrid::ClearGrid()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < cols; column++)
		{
			CELL_life[row][column] = 0;
		}
	}
}

void LifeGrid::ToggleCell(int row, int col)
{
	if (IsBounded(row, col))
		CELL_life[row][col] = ~CELL_life[row][col];
}


