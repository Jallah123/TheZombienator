#pragma once
#include "MenuScreen.h"

class LoadGameScreen :
	public MenuScreen
{
public:
	LoadGameScreen(SDL_Renderer* ren);
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	~LoadGameScreen();
};

