#include "TetrisGrid.h"
#include "TetrisGrid.h"
#include "TetrisGrid.h"
#include "TetrisGrid.h"
#include "TetrisGrid.h"
#include "Colors.h"
#include <iostream>

using namespace std;

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initialization();
	Display();

	colors = GetCellColors();
}

void Grid::Initialization()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++) 
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Display()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			cout << grid[row][column] << " ";
		}
	}

	cout << "/n";
}


void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * cellSize+11, row * cellSize+11, cellSize-1, cellSize - 1, colors[cellValue]);
		}
	}
}

bool Grid::IsBlockOffBounds(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols)
		return false;

	return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
		return true;

	return false;
}

bool Grid::IsRowFull(int row)
{
	for (int col = 0; col < numCols; col++)
	{
		if (grid[row][col] == 0)
			return false;
	}
	
	return true;
}

void Grid::ClearRow(int row)
{
	for (int col = 0; col < numCols; col++)
	{
		grid[row][col] = 0;
	}
}

void Grid::MoveRowsDown(int row, int numRows)
{
	for (int col = 0; col < numCols; col++)
	{
		grid[row + numRows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}


int Game::ClearFullRows()
{
	int rowsFull = 0;

	for (int row = numRows - 1; row >= 0; row--)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			rowsFull--;
		}
		else if (rowsFull > 0)
			MoveRowsDown(row, rowsFull);
	}

	return rowsFull;
}