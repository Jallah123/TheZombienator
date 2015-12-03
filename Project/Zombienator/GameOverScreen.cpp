#include "GameOverScreen.h"
#include "BackToMenuButton.h"
#include "StatsController.h"
#include "LabelEndScreen.h"

GameOverScreen::GameOverScreen(SDL_Renderer* ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/gameover_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/gameover.wav", 1);

	// Buttons
	BackToMenuButton* btnBack = new BackToMenuButton(*ren, "", "assets/images/button_backtomenu.png");
	AddUIComponent(btnBack);

	// Labels
	LabelEndScreen* lblStats = new LabelEndScreen(*ren, "Statistics: ", 900, 200);
	LabelEndScreen* lblTime = new LabelEndScreen(*ren, "Time: ", 900, 230);
	LabelEndScreen* lblWaves = new LabelEndScreen(*ren, "Waves: ", 900, 260);
	LabelEndScreen* lblKills = new LabelEndScreen(*ren, "Kills: ", 900, 290);
	LabelEndScreen* lblBullets = new LabelEndScreen(*ren, "Bullets: ", 900, 320);
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

	LabelEndScreen* valTime = new LabelEndScreen(*ren, tTime, 1000, 230);
	LabelEndScreen* valWaves = new LabelEndScreen(*ren, tWaves, 1000, 260);
	LabelEndScreen* valKills = new LabelEndScreen(*ren, tKills, 1000, 290);
	LabelEndScreen* valBullets = new LabelEndScreen(*ren, tBullets, 1000, 320);
	AddUIComponent(valTime);
	AddUIComponent(valWaves);
	AddUIComponent(valKills);
	AddUIComponent(valBullets);
}

GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::Update(float dt)
{
}

void GameOverScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}