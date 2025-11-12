#pragma once
#include "SpaceShip.hpp"
#include "ObstacleObj.h"
#include "alienAI.h"
#include "mysteryShip.hpp"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void Draw();
	void Update();
	void HandleInput();
	int playerLives;
	int gameScore;
	int highScore;
	bool gameRunning;
	Music music;

private:
	Spaceship spaceship;
	MysteryShip mysteryship;
	void DeleteInactiveLasers();
	void MoveAliens_LtoR();
	void MoveAliensDown(int distance);
	int aliensDirection;
	void ShootAlienLaser();
	void CollisionDetection();
	void InitGame();
	void ResetGame();
	void CheckNewHighScore();
	void saveHighScore(int PBscore);
	void loadPBscore();
	constexpr static float ShootingInterval_Aliens = 0.3;
	float timeLastShot;
	float SpawnMysteryShip_Interval,
		  timeLastSpawn;

	vector<Obstacle> CreateObstacles();
	vector<Alien> CreateAlien();
	vector<Obstacle> obstacles;
	vector<Alien> aliens;
	vector<Laser> alienLasers;
	Sound ExplodSound;
}