#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(SDL_Renderer* ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/gameover_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/gameover.wav", 0);
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
