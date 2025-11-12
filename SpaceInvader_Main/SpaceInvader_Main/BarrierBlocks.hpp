#pragma once
#include <raylib.h>

class BarrierBlock
{
public:
	BarrierBlock(Vector2 position);
	void Draw();
	Rectangle getRect();
private:
	Vector2 position;
};