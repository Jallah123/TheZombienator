#pragma once
#include "MenuScreen.h"
class HomeScreen :
	public MenuScreen
{
public:
	HomeScreen(SDL_Renderer* ren);
	~HomeScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

