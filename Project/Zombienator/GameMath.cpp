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
	return sqrt(pow(g1.getPosX() + (g1.GetWidth() / 2) - g2.getPosX() + (g2.GetWidth() / 2), 2) + pow(g1.getPosY() + (g1.GetHeight() / 2) - g2.getPosY() + (g2.GetHeight() / 2), 2));
}
