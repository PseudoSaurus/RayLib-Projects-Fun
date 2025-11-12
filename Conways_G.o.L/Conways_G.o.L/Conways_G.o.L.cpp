// Conways_G.o.L.cpp : Defines the entry point for the application.
//

#include "Conways_G.o.L.h"
#include "simulation.h"

#include <raylib.h>

using namespace std;

int main()
{
	// Game Colors
	Color GREY = { 29,29,29,255 };

	const int WINDOW_WIDTH = 750,
			  WINDOW_HEIGHT = 750,
			  CELL_SIZE = 25;

	int FPS = 15;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);
	Simulation GameSimulate(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

	// Simulation Loop
	while (WindowShouldClose() == false)
	{
		// Event Handling
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y / CELL_SIZE,
				col = mousePosition.x / CELL_SIZE;

			GameSimulate.ToggleCell(row, col);
		}

		if (IsKeyPressed(KEY_ENTER))
		{
			GameSimulate.StartSim();
			SetWindowTitle("The Game of Life is running rn...");
		}
		else if (IsKeyPressed(KEY_SPACE))
		{
			GameSimulate.StopSim();
			SetWindowTitle("The Game of Life has paused.\t Thank you for Playing!!!")
		}
		else if (IsKeyPressed(KEY_F || KEY_W))
		{
			FPS += 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_S))
		{
			if (FPS > 5)
				FPS += 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_R))
			GameSimulate.CreateRandLife();

		else if (IsKeyPressed(KEY_C))
			GameSimulate.ClearGrid();

		// Uodating Window
		GameSimulate.UpdateGrid();

		// Drawing New Life
		BeginDrawing();
		ClearBackground(GREY);
		GameSimulate.Draw();
		EndDrawing();
	}

	closeWindow();
}
