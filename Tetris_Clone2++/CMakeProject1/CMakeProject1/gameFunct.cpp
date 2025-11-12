#include "gameFunct.h"
#include <random>

Game::Game()
{
	grid = Grid();
	GameOver = false;
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameScore = 0;
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}

	int randIndex = rand() % blocks.size();
	Block block = blocks[randIndex];

	blocks.erase(blocks.begin() + randIndex);
	return block;
}

vector<Block> Game::GetAllBlocks()
{
	return { I_Block(), T_Block(), Sqr_Block(), Z_Block(), ReverZ_Block(), L_Block(), ReverL_Block() };

}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw(11,11);

	switch(nextBlock.ID)
	{
	// Allinement for I
	case 2:
		nextBlock.Draw(255, 290);
		break;

	// Allinement of Square block
	case 6:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}


void Game::HandleInput()
{
	int KeyPlayerInput = GetKeyPressed();
	
	// Reset the Game
	if (GameOver && KeyPlayerInput != 0)
	{
		GameOver = false;
		ResetGame();
	}

	if (!GameOver)
	{
		switch (KeyPlayerInput)
		{
			case KEY_LEFT:
				MoveBlock_Left();
				break;

			case KEY_RIGHT:
				MoveBlock_Right();
				break;		
		
			case KEY_DOWN:
				MoveBlock_Down();
				ScoreIncrement(0, 1);
				break;

			case KEY_UP || KEY_SPACE:
				RotateBlock();
				break;
		}
	}
	
}

void Game::MoveBlock_Left()
{
	if (!GameOver)
	{
		currentBlock.Movement(0, -1);

		if (IsBlockOffBounds || DoesBlockFit() == false)
			currentBlock.Movement(0, 1);

	}
}

void Game::MoveBlock_Right()
{
	if (!GameOver)
	{
		currentBlock.Movement(0, 1);

		if (IsBlockOffBounds || DoesBlockFit() == false)
			currentBlock.Movement(0, -1);
	}
}
void Game::MoveBlock_Down()
{
	if (!GameOver)
	{
		currentBlock.Movement(1, 0);

		if (IsBlockOffBounds || DoesBlockFit() == false)
			currentBlock.Movement(1, 0);
	}
}

bool Game::IsBlockOffBounds()
{
	vector<BlockPosition> tiles = currentBlock.GetCellPosition();

	for (BlockPosition item : tiles) 
	{
		grid.IsBlockOffBounds(item.row, item.column) ? true : false;
	}
}

bool Game::DoesBlockFit()
{
	vector<BlockPosition> tiles = currentBlock.GetCellPosition();

	for (BlockPosition item : tiles)
	{
		if(grid.IsCellEmpty(item.row, item.column) == false)
			return false;
	}

	return true;
}

void Game::RotateBlock()
{
	if (!GameOver)
	{
		currentBlock.Rotate();

		if (IsBlockOffBounds || DoesBlockFit() == false)
			currentBlock.UndoRotation();
	}
}

void Game::LockBlock()
{
	vector<BlockPosition> tiles = currentBlock.GetCellPosition();

	for (BlockPosition item: tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.ID;
	}
	currentBlock = nextBlock;

	if (DoesBlockFit == false)
		GameOver = true;


	nextBlock = GetRandomBlock();
	int NumrowsCleared = grid.ClearFullRows();
	ScoreIncrement(NumrowsCleared, 0);
}

void Game::ResetGame()
{
	grid.Initialization();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::ScoreIncrement(int linesCleared, int Points)
{
	switch(linesCleared)
	{
	case 1:
		gameScore += 100;
		break;
	case 2:
		gameScore += 300;
		break;
	case 3:
		gameScore += 500;
		break;
	default:
		break;
	}

	gameScore += Points*5;
}
