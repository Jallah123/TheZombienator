#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"

class LoadingScreen : public AbstractScreen
{
public:
	LoadingScreen(SDL_Renderer* ren);
	~LoadingScreen();

	virtual void Update(float dt) override;
};