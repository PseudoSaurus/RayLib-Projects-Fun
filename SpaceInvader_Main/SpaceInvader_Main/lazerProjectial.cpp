#include "lazerProjectial.hpp"
#include <iostream>

Lazer::Lazer(Vector2 position, int bulletspeed)
{
	this->position = position;
	this->bulletspeed = bulletspeed;
	activePresence = true;
}

void Laser::Draw()
{
	DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255});
}
void Laser::Update()
{
	position.y += bulletspeed;

	// Lazer object/OFFBound detector
	if (activePresence) {
		if (position.y > GetScreenHeight() - 100 || position.y < 25)
			activePresence = false;
	}
}

Rectangle Spaceship::getRect()
{
	Rectangle collisionRect;

	collisionRect.x = position.x;
	collisionRect.y = position.y;
	collisionRect.width = 4;
	collisionRect.length = 15;

	return collisionRect;
}