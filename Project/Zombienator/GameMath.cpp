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
	return sqrt(pow((g1.getPosX() + (g1.GetWidth() / 2)) - (g2.getPosX() + (g2.GetWidth() / 2)), 2) + pow((g1.getPosY() + (g1.GetHeight() / 2)) - (g2.getPosY() + (g2.GetHeight() / 2)), 2));
}

double GameMath::Distance(SDL_Rect & d1, SDL_Rect & d2)
{
	return sqrt(pow((d1.x + (d1.w / 2)) - (d2.x + (d2.w / 2)), 2) + pow((d1.y + (d1.h / 2)) - (d2.y + (d2.h / 2)), 2));
}
