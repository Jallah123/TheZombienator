#pragma once
#include "WinScreen.h"
#include "AbstractUIComponent.h"

WinScreen::WinScreen(SDL_Renderer* ren) : StatsScreen(ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/bg/win_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/youvewon.flac", 1);

	AddStats(ren);
}

WinScreen::~WinScreen() {}
void WinScreen::Update(float dt) {}

void WinScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
