#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"

class WinScreen : public AbstractScreen
{
public:
	WinScreen(SDL_Renderer* ren);
	~WinScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
};