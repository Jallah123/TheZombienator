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
	static bool LineIntersectsRect(SDL_Point * p1, SDL_Point * p2, SDL_Rect * rect, Direction dir);
};

