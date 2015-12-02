#include "GameOverScreen.h"
#include "Label.h"
#include "BackToMenuButton.h"
#include "StatsController.h"

GameOverScreen::GameOverScreen(SDL_Renderer* ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/gameover_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/gameover.wav", 0);

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