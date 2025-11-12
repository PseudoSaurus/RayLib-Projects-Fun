#pragma once
#include <vector>
#include <map>
#include "BlockPosition.h"
#include "Colors.h"
#include "BlockObjects.cpp"

using namespace std;

class Block 
{
public:
	int ID;
	
	Block();
	void Draw(int offsetX, int offsetY);
	void Movement(int rows, int columns);
	void Rotate();
	void UndoRotation();

	map<int, vector<BlockPosition>> cells;
	vector<BlockPosition> GetCellPosition();

private:
	int cellSize, rotationState;
	vector<Color> colors;

	int rowOffSet, columnOffSet;
};