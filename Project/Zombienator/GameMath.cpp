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
