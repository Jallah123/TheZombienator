#pragma once
#include "MenuScreen.h"
class HelpScreen :
	public MenuScreen
{
public:
	HelpScreen(SDL_Renderer* ren);
	~HelpScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

