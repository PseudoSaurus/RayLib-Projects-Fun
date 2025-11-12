// SpaceInvader_Main.cpp : Defines the entry point for the application.
//

#include <raylib.h>
#include "SpaceInvader_Main.h"
#include "game.hpp"
#include "ObstacleObj.h"
#include <string.h>
using namespace std;

string FormatWithLeadingZeros(int num, int width)
{
	string numberText = to_string(gameCommand.gameScore);
	int leadingZeros = 5 - numberText.length();
	numberText = string(leadingZeros, '0') + numberText;
}


int UIoffset = 50;

void GameUI_texts(Font font, Color yellow)
{
	if (game.isRunning)
	{
		DrawTextEx(font, "LVL 01", { 570, 740 }, 34, 2, yellow);
		DrawTextEx(font, "SCORE", { 50,15 }, 34, 2, yellow);
	}
	else
		DrawTextEx(font, "GAME OVER, AGAIN!!!", { 570, 740 }, 34, 2, yellow);
}

int main()
{
	Color grey = { 29,29,27,255 },
		yellow = { 243,216,63,255 };

	int windowWidth = 750,
		windowHeight = 700,
	
	SetTargetFPS(80);
	InitWindow(windowWidth + UIoffset, windowHeight + 2*UIoffset, "C++ Space Invaders");
	
	Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);

	Game gameCommand;
	Obstacle CoverFire = Obstacle({ 100,100 });

	// Game loop
	while (WindowShouldClose() == false) 
	{
		gameCommand.HandleInput();
		UpdateMusicStream(gameCommand.music);

		InitAudioDevice();
		gameCommand.Update();
		BeginDrawing();
		ClearBackground(grey);
		DrawRectangleRoundedLines({ 10,10,780,780 }, 0.18f, 20, 2, yellow);
		DrawLineEx({ 25, 730 }, { 775, 730 }, 3, yellow);
		GameUI_texts(font, yellow);
	
		//Displaying current player lives
		float X_coord = 50;
		for (int deadplayer = 0; deadplayer < gameCommand.playerLives; deadplayer++)
		{
			DrawTexture(spaceshipImage, { X_coord, 745, WHITE });
			X_coord += 50;
		}

		string scoreText = FormatWithLeadingZeros(gameCommand.gameScore, 5);
		DrawTextEx(font, scoreText.c_str(), { 50, 40 }, 34, 2, yellow);
		
		DrawTextEx(font, "HIGH SCORE", { 50,15 }, 34, 2, yellow);
		string highScoreTXT = FormatWithLeadingZeros(gameCommand.highScore, 5);
		DrawTextEx(font, scoreText.c_str(), { 655, 40 }, 34, 2, yellow);

		gameCommand.Draw();
		CoverFire.Draw();

		EndDrawing();
	}
	
	CloseWindow();
	CloseAudioDevice();
}

