#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include "StatsScreen.h"

class WinScreen : public StatsScreen
{
public:
	WinScreen(SDL_Renderer* ren);
	~WinScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};