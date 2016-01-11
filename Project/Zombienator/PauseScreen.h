#pragma once
#include "MenuScreen.h"

class PauseScreen :
	public MenuScreen
{
public:
	void Resume();
	void Settings();
	void Quit();

	PauseScreen(SDL_Renderer* ren);
	~PauseScreen();
	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};

