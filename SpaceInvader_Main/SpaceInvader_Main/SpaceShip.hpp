#pragma once 
#include <raylib.h>
#include <vector>
#include "lazerProjectial.hpp"

using namespace std;

class Spaceship{
public:
	Spaceship();
	~Spaceship();

	void Draw();
	void MoveLeft();
	void MoveRight();
	void FireLaser();
	void ResetGame();
	Rectangle getRect();
	vector<Laser> lasers;

private:
	Texture2D image;
	Vector2 position;
	double lastFireTime;
	Sound FiredLaserSound;
};