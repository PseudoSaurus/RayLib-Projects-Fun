#include "alienAI.h"

Texture2D Alien::AlienImages[3] = {};

Alien::Alien(int type, Vector2 position)
{
	this->type = type;
	this->position = position;

    if (AlienImages[type - 1].id == 0)
    {
	    switch(type)
	    {
	         case 1:
                 AlienImages[0] = LoadTexture("Graphics/alien_1.png");
                 break;
             case 2:
                 AlienImages[1] = LoadTexture("Graphics/alien_2.png");
                 break;
             case 3:
                 AlienImages[2] = LoadTexture("Graphics/alien_3.png");
                 break;
             default:
                 AlienImages[0] = LoadTexture("Graphics/alien_1.png");
                 break;
	    }
    }


}

void Alien::Draw() 
{
	DrawTextureV(AlienImages[type-1], position, WHITE);
}

int Alien::GetAlienType()
{
	return type;
}

void Alien::UnloadImage()
{
    for (int index = 0; index < 4; index++)
    {
        UnloadTexture(AlienImages[index]);
    }
}

void Alien::Update(int direction)
{
    position.x += direction;
}

Rectangle alienAI::getRect()
{
    return { position.x, position.y, 
             float(AlienImages[type-1].width), 
             float(AlienImages[type-1].height)};
}