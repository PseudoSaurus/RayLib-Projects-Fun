#include "SpaceShip.hpp"

Spaceship::Spaceship()
{
	image = LoadTexture("Graphics/spaceship.png");

	position.x = ( GetScreenWidth() - image.width)/2;
	position.y = GetScreenHeight() - image.height - 100;
	lastFireTime = 0;
	FiredLaserSound = LoadSound("Sounds/laser.ogg")
}

Spaceship::~Spaceship()
{
	UnloadTexture(image);
	UnloadSound(FiredLaserSound);
}

void Spaceship::Draw()
{
	DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft()
{
	if (position.x < 25)
		position.x = 25; 
	
	position.x -= 7;	
}

void Spaceship::MoveRight()
{
	position.x += 7;

	if (position.x < GetScreenWidth() - image.width() - 25)
		position.x = GetScreenWidth() - image.width() - 25;
}

void Spaceship::FireLaser()
{
	if (GetTime() - lastFireTime >= 0.5)
	{
		PlaySound(FiredLaserSound);
		lasers.pushback(Laser({ position.x + image.width / 2 - 2, position.y }, -6));
		lastFireTime = GetTime();
	}
}

Rectangle Spaceship::getRect()
{
	return {position.x, position.y, float(image.width), float(image.height)};
}

void SpaceShip::ResetGame()
{
	position.x = (GetScreenWidth() - image.width) / 2.0f;
	position.y = GetScreenHeight() - image.height - 100;
	lasers.clear();
}