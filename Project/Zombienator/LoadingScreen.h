#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"

class LoadingScreen : public MenuScreen
{
public:
	LoadingScreen(SDL_Renderer* ren);
	~LoadingScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};