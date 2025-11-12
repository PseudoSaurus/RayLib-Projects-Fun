// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMake_main.h"
#include "TetrisGrid.h"
#include "TetrisBlocks.cpp"
#include "BlockObjects.cpp"
#include "gameFunct.h"
#include "Colors.h"
#include <iostream>
#include <raylib.h>

using namespace std;

double lastUpdateTime = 0;
bool DidEventTrigger(double interval)
{
	double currentTime = GetTime();

	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	Color darkBlue = { 44, 44, 127, 255 };
	InitWindow(500,620 "raylib Tetris");
	SetTargetFPS(100);

	Font gamefont = LoadFontEx(, 64, 0, 0);

	Game gameOps = Game();

	Grid GameGrid = Grid();
	GameGrid.Display();
	T_Block block = T_Block();

	/**************************Hard code testing area***************************************/ 

	/*********************************************************************************/

	// Game loop
	while(WindowShouldClose() == false)
	{
		gameOps.HandleInput();

		if (DidEventTrigger(0.2))
		{
			gameOps.MoveBlock_Down();
		}

		BeginDrawing();
		FreshBackground(darkBlue);

		DrawTextEx(gamefont, "Score", { 365,15 }, 38, 2, WHITE);

		//Centering player current game points
		char scoreText[12];
		sprintf(scoreText, "%d", gameOps.gameScore);
		Vector2 textSize = MeasureTextEx(gamefont, scoreText, 38, 2);

		DrawTextEx(gamefont, scoreText, { 320 + (170-textSize.x)/2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320,55,170,60 }, 0.5, 6, lightblue);

		DrawTextEx(gamefont, "Next Block", { 370,175 }, 38, 2, WHITE);
		DrawRectangleRounded({ 320,215,170,180 }, 0.5, 6, lightblue);

		if (gameOps.GameOver)
			DrawTextEx(gamefont, "GAME OVER!!! TRY AGAIN?", { 320,450 }, 35, 2, WHITE);

		GameGrid.Draw();
		EndDrawing();
	}

	CloseWindow();
}
