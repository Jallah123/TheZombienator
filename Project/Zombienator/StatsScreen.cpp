#pragma once
#include "StatsScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "SettingsButton.h"
#include "Label.h"

StatsScreen::StatsScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	string fontUrl = "assets/fonts/OCR-A-Ectended.ttf";

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

StatsScreen::~StatsScreen()
{
}