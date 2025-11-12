#include "TetrisBlocks.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
}

void Block::Draw(int offestX, int offsetY)
{
	vector<BlockPosition> tiles = GetCellPosition();

	for (BlockPosition item : tiles)
		DrawRectangle(item.column * cellSize + offestX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[ID]);
}

void Block::Movement(int rows, int columns)
{
	rowOffSet += rows;
	columnOffSet += columns;
}

vector<BlockPosition> Block::GetCellPosition()
{
	vector<BlockPosition> tiles = cells[rotationState],
						  movedTiles;

	for (BlockPosition item : tiles) 
	{
		BlockPosition newPosition = BlockPosition(item.row + rowOffSet, item.column + columnOffSet);
		movedTiles.push_back(newPosition);
	}
}

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
		rotationState = 0;
}

void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
		rotationState = cells.size() - 1;
}