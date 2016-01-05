#include "GameOverScreen.h"
#include "AbstractUIComponent.h"

GameOverScreen::GameOverScreen(SDL_Renderer* ren) : StatsScreen(ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/gameover_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/gameover.wav", 1);

	AddStats(ren);
}

GameOverScreen::~GameOverScreen() {}
void GameOverScreen::Update(float dt) {}

void GameOverScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}