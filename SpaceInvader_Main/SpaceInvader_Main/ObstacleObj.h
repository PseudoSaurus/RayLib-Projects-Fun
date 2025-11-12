#pragma once
#include <vector>
#include "BarrierBlocks.hpp"

using namespace std;

class Obstacle
{
public:
	Obstacle(Vector2 postion);
	void Draw();
	Vector2 position;
	
	vector<BarrierBlock> blocks;
	static vector<vector<int>> grid;
private:
};
