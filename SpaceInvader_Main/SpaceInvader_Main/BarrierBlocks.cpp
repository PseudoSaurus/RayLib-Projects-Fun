#include "BarrierBlocks.hpp"

BarrierBlock::BarrierBlock(Vector2 position)
{
	this->position = position
}

void BarrierBlock::Draw() 
{
	//									pixial size, color of obj
	DrawRectangle(position.x, position.y, 3, 3, {243, 216, 63, 255});
}

Rectangle BarrierBlock::getRect()
{
	Rectangle collisionRect;

	collisionRect.x = position.x;
	collisionRect.y = position.y;
	collisionRect.width, collisionRect.length = 3;

	return collisionRect;
}