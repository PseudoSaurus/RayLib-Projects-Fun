#pragma once
#include "GameGrid.h"

class Simulation
{
public:
	Simulation(int width, int height, int cellSize)
		: grid(width, height, cellSize), tempGrid(width, height, cellSize), RunSim(false) { };
	void Draw();
	void SetCellValue(int row, int col, int value);
	void UpdateGrid();
	bool IsRunning() {return RunSim};
	int CountLiveNeighbors(int row, int col);
	void StartSim() { RunSim = true };
	void StopSim() { RunSim = false };
	void ClearGrid();
	void CreateRandLife();
	void ToggleCell(int row, int col);

private:
	LifeGrid grid;
	LifeGrid tempGrid;
	bool RunSim;
};