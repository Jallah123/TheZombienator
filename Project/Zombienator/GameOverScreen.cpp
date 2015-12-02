#include "GameOverScreen.h"
#include "Label.h"

GameOverScreen::GameOverScreen(SDL_Renderer* ren)
{
	SoundController::GetInstance().StopAllSounds();
	ChangeBackground(ren, "assets/images/gameover_bg.png");
	SoundController->GetInstance().PlaySound("assets/sounds/gameover.wav", 0);

	DrawStats(*ren);
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

void GameOverScreen::DrawStats(SDL_Renderer& ren)
{
	std::string fontUrl = "assets/fonts/OCR-A-Extended.ttf";
	
	Label* a = new Label(ren, "Kills", 100, 50, 18, fontUrl, { 255,255,255 });

	AddUIComponent(a);
}
