#pragma once
#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/bg/loading_bg.png");
}

LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::Update(float dt)
{
}

void LoadingScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
