#pragma once	
#include "TetrisGrid.h"
#include "TetrisBlocks.h"
#include <vector>

using namespace std;


class Game
{
public:
	Game();
	
	bool GameOver;
	void HandleInput();
	
	void MoveBlock_Down();
	int gameScore;

private:	
	Grid grid;
	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	bool IsBlockOffBounds();
	bool DoesBlockFit();
	void RotateBlock();
	void LockBlock();
	void ResetGame();
	void ScoreIncrement(int linesCleared, int Points);
	void MoveBlock_Left();
	void MoveBlock_Right();

	vector<Block> blocks;
	Block currentBlock, nextBlock;
};
