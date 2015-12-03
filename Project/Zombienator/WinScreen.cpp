#pragma once
#include "WinScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "LabelEndScreen.h"

WinScreen::WinScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/win_bg.png");

	string tKills = "Kills: " + std::to_string(StatsController::GetInstance()->GetTotalKills());
	string tWaves = "Waves Defeated: " + std::to_string(StatsController::GetInstance()->GetTotalWavesDefeated());

	// Elements
	BackToMenuButton* aButton = new BackToMenuButton(*ren, "", "assets/images/button_backtomenu.png");
	LabelEndScreen* aLabel = new LabelEndScreen(*ren, tKills, 642, 335);
	LabelEndScreen* bLabel = new LabelEndScreen(*ren, tWaves, 642, 365);
	
	// Add to UI
	AddUIComponent(aButton);
	AddUIComponent(aLabel);
	AddUIComponent(bLabel);

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
