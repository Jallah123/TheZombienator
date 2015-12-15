#pragma once
#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/loading_bg.png");
}

LoadingScreen::~LoadingScreen()
{
}

void LoadingScreen::Update(float dt)
{
}

void LoadingScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
}
