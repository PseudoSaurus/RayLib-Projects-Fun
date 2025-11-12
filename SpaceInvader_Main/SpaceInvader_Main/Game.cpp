#include "game.hpp"
#include <iostream>
#include <fstream>
using namespace std;


Game::Game()
{
	obstacles = CreateObstacles();
	aliens = CreateAlien();
	aliensDirection = 1;
	timeLastShot = 0;
	playerLives = 3;
	gameRunning = true;
	timeLastSpawn = 0.0;
	SpawnMysteryShip_Interval = GetRandomValue(10, 20);
	mysteryship.Spawn();
	
	music = LoadMusicStream("Sounds/music.ogg");
	ExplodSound = LoadSound("Sounds/explosion.ogg");
	PlayMusicStream(music);
}

Game::~Game()
{
	Alien::UnloadImage();
	UnloadMusicStream(music);
	UnloadSound(ExplodeSound);
}

void Game::Update() 
{
	double currentTime = GetTime();

	if (gameRunning)
	{
		if (currentTime - timeLastSpawn > SpawnMysteryShip_Interval)
		{
			mysteryship.Spawn();
			timeLastSpawn = GetTime();
			SpawnMysteryShip_Interval = GetRandomValue(10, 20);
		}

		for (auto& laser : spaceship.lasers)
		{
			laser.Update();
		}

		MoveAliens_LtoR();
		ShootAlienLaser();
		for (auto& laser : alienLasers)
		{
			laser.Update();
		}

		DeleteInactiveLasers();
		mysteryship.Update();
		CollisionDetection();
	}
	else
	{
		if (IsKeyDown(KEY_ENTER))
		{
			ResetGame();
			InitGame();
		}
	}
}


void Game::Draw()
{
	spaceship.Draw();
	mysteryship.Draw();

	for (auto& laser : spaceship.lasers) 
	{
		laser.Draw();
	}

	for (auto& obstacle : obstacles)
	{
		obstacle.Draw();
	}
	
	for (auto& alien : aliens)
	{
		alien.Draw();
	}
	
	for (auto& laser : alienLasers)
	{
		laser.Draw();
	}


}

void Game::HandleInput()
{
	if (gameRunning)
	{
		if (IsKeyDown(KEY_LEFT))
			spaceship.MoveLeft();

		if (IsKeyDown(KEY_RIGHT))
			spaceship.MoveRight();

		if (IsKeyDown(KEY_SPACE))
			spaceship.FireLaser();

	}
	
}

void Game::DeleteInactiveLasers()
{
	for( auto items=spaceship.lasers.begin(); items != spaceship.lasers.end();) 
	{
		if (!items->active)
			items = spaceship.lasers.erase(items);
		else
			++items;
	}
	
	for( auto items=alienLasers.begin(); items != alienLasers.end();) 
	{
		if (!items->active)
			items = alienLasers.erase(items);
		else
			++items;
	}
}

void Game::MoveAliens_LtoR()
{
	for (auto& alien : aliens)
	{
	
		if (alien.position.x + alien.AlienImage[alien.type - 1].width > GetScreenWidth() - 25)
		{
			aliensDirection = -1;
			MoveAliensDown(4);
		}

		if (alien.position.x < 25)
		{
			aliensDirection = 1;
			MoveAliensDown(4);
		}	
		alien.Update(aliensDirection);
	}
}

void Game::MoveAliensDown(int distance)
{
	for (auto& alien : aliens)
	{
		alien.position.y += distance;
	}
}

void Game::ShootAlienLaser()
{
	double currentTime = GetTime();

	if (currentTime - timeLastShot >= ShootingInterval_Aliens && !aliens.empty())
	{
		int randIndex = GetRandomValue(0, aliens.size() - 1);
		Alien& alien = aliens[randIndex];

		alienLasers.push_back(Laser({alien.position.x + alien.AlienImage[alien.type - 1].width / 2,
									alien.position.y + alien.AlienImage[alien.type - 1].height }, 6));
		timeLastShot = GetTime();
	}
	
	
}

void Game::CollisionDetection()
{
	//Player's laser hitmarker
	for (auto& laser : spaceship.lasers)
	{
		auto alienIterator = aliens.begin();
		while (alienIterator != aliens.end())
		{
			if (CheckCollisionRecs(alienIterator->getRect(), laser.getRect()))
			{
				PlaySound(ExplodSound);

				//Scoring the kills
				switch (alienIterator->type)
				{
					case 1:
						gameScore += 100;
						break;
					case 2:
						gameScore += 200;
						break;
					case 3:
						gameScore += 300;
				}
					
				alienIterator = aliens.erase(alienIterator);
				laser.appear(false);
				CheckNewHighScore();
			}
			else
				alienIterator++;
		}

		//Collisions for the barrier blocks
		for (auto& obstacle : obstacles)
		{
			auto obstacleIterator = obstacle.blocks.begin();
			while (obstacleIterator != obstacle.blocks.end())
			{
				if (CheckCollisionRecs(obstacleIterator->getRect(), laser.getRect()))
				{
					obstacleIterator = obstacle.blocks.erase(obstacleIterator);
					laser.appear(false);
				}
				else
					obstacleIterator++;
			}
		}

		if (CheckCollisionRecs(mystership.getRect(), laser.getRect()))
		{
			mysteryship.appear = false;
			laser.activePresence(false);
			PlaySound(ExplodSound);
			gameScore += 500;
			CheckNewHighScore();
		}
	}

	//Alien's laser hitmarker
	for (auto& laser : alienLasers)
	{
		if (CheckCollisionRecs(laser.getRect(), spaceship.getRect()))
		{
			laser.activePresence(false);
			cout << "Player's ship has been HIT!!!" << endl;
			playerLives--;

			if (playerLives == 0)
				GameOver();
		}

		for (auto& obstacle : obstacles)
		{
			auto obstacleIterator = obstacle.blocks.begin();
			while (obstacleIterator != obstacle.blocks.end())
			{
				if (CheckCollisionRecs(obstacleIterator->getRect(), laser.getRect()))
				{
					obstacleIterator = obstacle.blocks.erase(obstacleIterator);
					laser.appear(false);
				}
				else
					obstacleIterator++;
			}
		}
	}

	//Alien collides an Barrier obstacle or Player
	for (auto& alien : aliens)
	{
		for (auto& obstacle : obstacles)
		{
			for (auto& obstacle : obstacles)
			{
				auto obstacleIterator = obstacle.blocks.begin();
				while (obstacleIterator != obstacle.blocks.end())
				{
					if (CheckCollisionRecs(obstacleIterator->getRect(), alien.getRect()))
						obstacleIterator = obstacle.blocks.erase(obstacleIterator);
					
					else
						obstacleIterator++;
				}
			}
		}
		if (CheckCollisionRecs(alien.getRect(), spaceship.getRect()))
		{
			cout << "\t\t!!!!Aliens have CRASH into your spaceship crashed!!!!" << endl;
			GameOver();
		}
	}
}

vector<Obstacle> Game::CreateObstacles()
{
	int obstacleWidth = Obstacle::grid[0].size() * 3;

	float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5;

	for (int index = 0; index < 4; index++)
	{
		float offsetX = (index + 1) * gap + index * obstacleWidth;

		obstacles.push_back(Obstacle({ offsetX, float(GetSCreenHeight() - 200) }));
	}

	return obstacles;
}

vector<Alien> Game::CreateAlien()
{
	vector<Alien> aliens;
	int alienType = 3;

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 11; col++)
		{			
			row <= 2 && row > 0 ? alienType = 2 : alienType = 1;

			float x = 75 + col * 55,
			      y = 110 + row * 55;
			aliens.push_back(Alien(alienType, {x,y }));

		}
	}
	return aliens;
}

void Game::GameOver()
{
	cout << "*****************\tGAME OVER\t**************" << endl;
	gameRunning = false;
}

void Game::InitGame()
{
	obstacles = CreateObstacles();
	aliens = CreateAlien();
	aliensDirection = 1;
	timeLastShot = 0.0;
	timeLastSpawn = 0.0;
	playerLives = 3;
	gameScore = 0;
	highScore = loadPBscore();
	gameRunning = true;
	SpawnMysteryShip_Interval = GetRandomValue(10,20);
}

void Game::ResetGame()
{
	spaceship.ResetGame();
	aliens.clear();
	obstacles.clear();
	alienLasers.clear();
}

void Game::CheckNewHighScore()
{
	if (gameScore > highScore)
	{	
		highScore = gameScore;
		saveHighScore(highScore);
	}
}

void Game::saveHighScore(int PBscore)
{
	ofstream highscoreFile("PBgameScore.txt");

	if (highscoreFile.is_open())
	{
		highscoreFile << PBscore;
		highscoreFile.close();
	}
	else
		cerr << "Your High Score failed to save in game" << endl;
	
}

int Game::loadPBscore()
{
	int highScore = 0;
	ifstream highscoreFile("PBgameScore.txt");

	if (highscoreFile.is_open())
	{
		highscoreFile >> highScore;
		highscoreFile.close();
	}
	else
		cerr << "Your High Score failed to load in game" << endl;

	return highScore
}