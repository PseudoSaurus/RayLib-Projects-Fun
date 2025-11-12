#include "BlockPosition.h"
#include "TetrisBlocks.h"

class L_Block :public Block
{
public:
	L_Block()
	{
		ID = 0;
		cells[0] = { BlockPosition(0,2), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2) };
		cells[1] = { BlockPosition(0,1), BlockPosition(1,1), BlockPosition(2,1), BlockPosition(2,2) };
		cells[2] = { BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,0) };
		cells[3] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,1), BlockPosition(2,1) };
		Movement(0, 3);
	}
};

class ReverL_Block :public Block
{
public:
	ReverL_Block()
	{
		ID = 1;
		cells[0] = { BlockPosition(0,0), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2) };
		cells[1] = { BlockPosition(0,1), BlockPosition(0,2), BlockPosition(1,1), BlockPosition(2,1) };
		cells[2] = { BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,2) };
		cells[3] = { BlockPosition(0,1), BlockPosition(1,1), BlockPosition(2,0), BlockPosition(2,1) };
		Movement(0, 3);
	}
}; 

class I_Block :public Block
{
public:
	I_Block()
	{
		ID = 2;
		cells[0] = { BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(1,3) };
		cells[1] = { BlockPosition(0,2), BlockPosition(1,2), BlockPosition(2,2), BlockPosition(3,2) };
		cells[2] = { BlockPosition(2,0), BlockPosition(2,1), BlockPosition(2,2), BlockPosition(2,3) };
		cells[3] = { BlockPosition(0,1), BlockPosition(1,1), BlockPosition(2,1), BlockPosition(3,1) };
		Movement(-1, 4);
	}

};

class T_Block :public Block
{
public:
	T_Block()
	{
		ID = 3;
		cells[0] = { BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2) };
		cells[1] = { BlockPosition(0,1), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,1) };
		cells[2] = { BlockPosition(1,0), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,1) };
		cells[3] = { BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(2,1) };
		Movement(0, 3);
	}

};

class ReverZ_Block :public Block
{
public:
	ReverZ_Block()
	{
		ID = 4;
		cells[0] = { BlockPosition(0,1), BlockPosition(0,2), BlockPosition(1,0), BlockPosition(1,1) };
		cells[1] = { BlockPosition(0,1), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,2) };
		cells[2] = { BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,0), BlockPosition(2,1) };
		cells[3] = { BlockPosition(0,0), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(2,1) };
		Movement(0, 3);
	}

};

class Z_Block :public Block
{
public:
	Z_Block()
	{
		ID = 5;
		cells[0] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,1), BlockPosition(1,2) };
		cells[1] = { BlockPosition(0,2), BlockPosition(1,1), BlockPosition(1,2), BlockPosition(2,1) };
		cells[2] = { BlockPosition(1,0), BlockPosition(1,1), BlockPosition(2,1), BlockPosition(2,2) };
		cells[3] = { BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1), BlockPosition(2,0) };
		Movement(0, 3);
	}

};

class Sqr_Block :public Block
{
public:
	Sqr_Block()
	{
		ID = 6;
		cells[0] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1) };
		cells[1] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1) };
		cells[2] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1) };
		cells[3] = { BlockPosition(0,0), BlockPosition(0,1), BlockPosition(1,0), BlockPosition(1,1) };
		Movement(0, 4);
	}

};