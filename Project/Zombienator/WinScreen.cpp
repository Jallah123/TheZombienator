#pragma once
#include "WinScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "SettingsButton.h"
#include "Label.h"

WinScreen::WinScreen(SDL_Renderer* ren) : StatsScreen(ren)
{
	ChangeBackground(ren, "assets/images/win_bg.png");
}

WinScreen::~WinScreen()
{
}

void WinScreen::Update(float dt)
{

}

void WinScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
