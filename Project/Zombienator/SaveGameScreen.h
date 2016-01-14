#pragma once
#include "MenuScreen.h"

class SaveGameScreen :
	public MenuScreen
{
public:
	SaveGameScreen(SDL_Renderer* ren);
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	~SaveGameScreen();
};