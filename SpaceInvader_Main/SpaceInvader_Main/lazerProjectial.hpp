#pragma once
#include <raylib.h>

class Laser()
{
public:
	Laser(Vector2 position, int bulletspeed);
	void Update();
	void Draw();
	bool activePresence();
	Rectangle getRect();

private:
	Vector2 position:
	int bulletspeed;
}