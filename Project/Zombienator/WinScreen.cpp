#pragma once
#include "WinScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "SettingsButton.h"
#include "Label.h"

WinScreen::WinScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/win_bg.png");
	//std::string fontUrl = "assets/fonts/OCR-A-Extended.ttf";

	string fontUrl = "assets/fonts/Block-Cartoon.ttf";
	string totalKillsString = "Kills: " + std::to_string(StatsController::Instance()->GetTotalKills());
	string totalWavesDefeatedString = "Waves Defeated: " + std::to_string(StatsController::Instance()->GetTotalWavesDefeated());

	// Elements
	BackToMenuButton* aButton = new BackToMenuButton(*ren, "", "assets/images/button_backtomenu.png");
	Label* aLabel = new Label(*ren, strdup(totalKillsString.c_str()), 642, 335, 18, fontUrl, { 255,255,255 });
	Label* bLabel = new Label(*ren, strdup(totalWavesDefeatedString.c_str()), 642, 365, 18, fontUrl, { 255,255,255 });
	
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
