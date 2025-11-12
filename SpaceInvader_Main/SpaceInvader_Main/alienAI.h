#pragma once 
#include <raylib.h>

class Alien
{
public:
	Alien(int type, Vector2 position);

	void Update(int direction);
	void Draw();
	int GetAlienType();
	static void UnloadImage();
	static Texture2D AlienImage[3];
	int type;
	Vector2 position;
	Rectangle getRect();

private:
};