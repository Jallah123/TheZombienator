#pragma once
#include "WinScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "SettingsButton.h"
#include "Label.h"

WinScreen::WinScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/win_bg.png");

	// Get stats
	int totalKills = StatsController::Instance()->GetTotalKills();
	int totalWavesDefeated = StatsController::Instance()->GetTotalWavesDefeated();

	// Convert to char
	char totalKillsConverted[32];
	sprintf(totalKillsConverted, "%d", totalKills);
	char totalWavesDefeatedConverted[32];
	sprintf(totalWavesDefeatedConverted, "%d", totalWavesDefeated);

	// Add to string
	char totalKillsString[64] = " Kills: ";
	strcat(totalKillsString, totalKillsConverted);
	char totalWavesDefeatedString[64] = " Waves Defeated: ";
	strcat(totalWavesDefeatedString, totalWavesDefeatedConverted);

	// Elements
	BackToMenuButton* aButton = new BackToMenuButton(*ren, "", "assets/images/button_backtomenu.png");
	Label* aLabel = new Label(*ren, totalKillsString, 642, 335, 20, { 255,255,255 });
	Label* bLabel = new Label(*ren, totalWavesDefeatedString, 642, 365, 20, { 255,255,255 });
	
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
