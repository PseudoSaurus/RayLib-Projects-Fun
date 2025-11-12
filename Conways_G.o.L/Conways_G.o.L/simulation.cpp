#include "simulation.h"
#include <vector>
#include <utility>

using namespace std;

void Simulation::Draw()
{
	grid.DrawGrid();
}

void Simulation::SetCellValue(int row, int col, int value)
{
	grid.SetCellValue(row, col, value);
}



int Simulation::CountLiveNeighbors(int row, int col)
{
	int liveNeighbors = 0;

	vector<pair<int, int>> cellOffSets =
	{
		{-1,-1},	//Top Left Cell 
		{-1,0},		//Top Center Cell
		{-1,1},		//Top Right Cell
		{0,-1},		//Left Cell
		{0,1},		//Right Cell
		{1,-1},		//Bottom Left Cell
		{1,0},		//Bottom Center Cell
		{1,1}		//Bottom Right Cell
	};

	for (const auto& offset : cellOffSets)
	{
		int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows(),
			neighborColumn = (col + offset.second + grid.GetColumns()) % grid.GetColumns();

		liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
	}

	return liveNeighbors;
}

void Simulation::UpdateGrid()
{

	if (IsRunning())
	{
		for (int row = 0; row < grid.GetRows(); row++)
		{
			for (int cols = 0; cols < grid.GetColumns(); cols)
			{
				int liveNeighbors = CountLiveNeighbors(row, cols), 
					cellValue = grid.GetValue(row, cols);

				if (cellValue)
				{
					if (liveNeighbors > 3 || liveNeighbors < 2)
						tempGrid.SetCellValue(row, cols, 0);
					else
						tempGrid.SetCellValue(row, cols, 1);
				}
				else
				{
					if (liveNeighbors == 3)
						tempGrid.SetCellValue(row, cols, 1);
					else
						tempGrid.SetCellValue(row, cols, 0);
				}
			}
		}

	}
	
	grid = tempGrid;

}

void Simulation::ClearGrid()
{
	if (!IsRunning())
		grid.ClearGrid();
}

void Simulation::CreateRandLife()
{
	if (!IsRunning())
		grid.FillRand();
}

void Simulation::ToggleCell(int row, int col)
{
	if (!IsRunning())
		grid.ToggleCell(row, col);
}