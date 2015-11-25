#include "GameMath.h"
#include <math.h>
#include "GameObject.h"

GameMath::GameMath()
{
}


GameMath::~GameMath()
{
}

double GameMath::Distance(GameObject& g1, GameObject& g2)
{
	return sqrt(pow(g1.getPosX() - g2.getPosX(), 2) + pow(g1.getPosY() - g2.getPosY(), 2));
}

bool GameMath::LineIntersectsRect(SDL_Point * p1, SDL_Point * p2, SDL_Rect * rect, Direction dir)
{
	if (dir == Direction::NORTH || dir == Direction::SOUTH)//check if 
		return p1->x >= rect->x && p1->x <= rect->x + rect->w &&
		p2->x >= rect->x && p2->x <= rect->x + rect->w;
	if(dir == Direction::EAST || dir == Direction::WEST)
		return p1->y >= rect->y && p1->y <= rect->y + rect->h &&
		p2->y >= rect->y && p2->y <= rect->y + rect->h;
	return false;
}
