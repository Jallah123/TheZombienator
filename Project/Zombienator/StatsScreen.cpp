#pragma once
#include "StatsScreen.h"
#include "StatsController.h"
#include "BackToMenuButton.h"
#include "SettingsButton.h"
#include "Label.h"
#include "LabelEndScreen.h"

StatsScreen::StatsScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
}

StatsScreen::~StatsScreen()
{
	delete highScores;
}


void StatsScreen::AddHighScores(SDL_Renderer* ren)
{
	AddUIComponent(new LabelEndScreen(*ren, "Highscores:", 100, 200));

	highScores = ioC->LoadFile("highscores", highScores);
	if (highScores == nullptr) {
		highScores = new HighScores();
	}
	highScores->Insert(StatsController::GetInstance()->GetTotalWavesDefeated());

	bool protectOnce = true;
	int count = 1;
	int startX = 230;
	for (auto& i : highScores->GetHighScores()) {
		AddUIComponent(new LabelEndScreen(*ren, to_string(count) + ": ", 100, startX));
		AddUIComponent(new LabelEndScreen(*ren, to_string(i), 125, startX));
		if (i == StatsController::GetInstance()->GetTotalWavesDefeated() && protectOnce) {
			protectOnce = false;
			AddUIComponent(new LabelEndScreen(*ren, "-> YOU!", 155, startX));
		}
		
		startX += 30;
		count++;
	}

	highScores->Save();
}

void StatsScreen::AddStats(SDL_Renderer* ren)
{
	//addHighscores
	AddHighScores(ren);

	// Buttons
	BackToMenuButton* btnBack = new BackToMenuButton(*ren, "", "assets/images/btn/btn_backtomenu.png");
	AddUIComponent(btnBack);

	// Labels
	LabelEndScreen* lblStats = new LabelEndScreen(*ren, "Statistics: ", 1000, 200);
	LabelEndScreen* lblTime = new LabelEndScreen(*ren, "Time: ", 1000, 230);
	LabelEndScreen* lblWaves = new LabelEndScreen(*ren, "Waves: ", 1000, 260);
	LabelEndScreen* lblKills = new LabelEndScreen(*ren, "Kills: ", 1000, 290);
	LabelEndScreen* lblBullets = new LabelEndScreen(*ren, "Bullets: ", 1000, 320);
	AddUIComponent(lblStats);
	AddUIComponent(lblTime);
	AddUIComponent(lblWaves);
	AddUIComponent(lblKills);
	AddUIComponent(lblBullets);

	// Values
	string tWaves = to_string(StatsController::GetInstance()->GetTotalWavesDefeated());
	string tKills = to_string(StatsController::GetInstance()->GetTotalKills());
	string tBullets = to_string(StatsController::GetInstance()->GetTotalBullets());
	string tTime = StatsController::GetInstance()->GetTotalTime();

	LabelEndScreen* valTime = new LabelEndScreen(*ren, tTime, 1100, 230);
	LabelEndScreen* valWaves = new LabelEndScreen(*ren, tWaves, 1100, 260);
	LabelEndScreen* valKills = new LabelEndScreen(*ren, tKills, 1100, 290);
	LabelEndScreen* valBullets = new LabelEndScreen(*ren, tBullets, 1100, 320);
	AddUIComponent(valTime);
	AddUIComponent(valWaves);
	AddUIComponent(valKills);
	AddUIComponent(valBullets);
}
