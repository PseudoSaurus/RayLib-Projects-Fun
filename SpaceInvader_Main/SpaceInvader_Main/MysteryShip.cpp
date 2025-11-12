#include "mysteryShip.hpp"
#include "SpaceInvader_Main.cpp" import UIoffset; 

MysteryShip::MysteryShip()
{
	shipImage = LoadTexture();
	appear = false;
}

MysteryShip::~MysteryShip()
{
	UnloadTexture(image);
}

void MysteryShip::Spawn()
{
	position.y = 90;
	int translationSide = GetRandomValue(0, 1);

	side == 0 ? position.x = UIoffSet/2, speed = 3 : position.x = GetScreenWidth() - shipImage.width - 25, speed = -3;
}

void MysteryShip::Update()
{
	if (appear)
	{
		position.x += speed;
		if (position.x > GetScreenWidth() - image.width - 25|| position.x < 25)
			appear = false;
	}
}

void MysteryShip::Draw()
{
	if (appear)
		DrawTextureV(shipIamge, position, WHITE);
}

Rectangle MysteryShip::getRect()
{
	if (appear)
		return { position.x, position.y, float(shipImage.width), float(shipImage.height) };
	else
		return { position.x, position.y, 0,0 };
}