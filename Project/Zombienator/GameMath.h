#pragma once
#include "Direction.cpp"
#include <SDL_rect.h>
class GameObject;
class GameMath
{
public:
	GameMath();
	~GameMath();

	static double Distance(GameObject& g1, GameObject& g2);
};

