#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"

class StatsScreen : public AbstractScreen
{
public:
	StatsScreen(SDL_Renderer* ren);
	~StatsScreen();

	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
};