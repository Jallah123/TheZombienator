#include "CreditScreen.h"

CreditScreen::CreditScreen(SDL_Renderer* ren) : MenuScreen(ren)
{	
	//default background
	ChangeBackground(ren, "assets/images/bg/default_bg.png");

	//back button
	BackButton* b = new BackButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);


	//plays sound:
	SoundController->ChangeMusic("assets/sounds/StandByMe.wav");

	//Credit text
	addTextToSet("Made by");
	addTextToSet(" ");

	addTextToSet("Sander de Haas");
	addTextToSet("Paul Laros");
	addTextToSet("Kenneth Mauriks");
	addTextToSet("Thomas Reijnders");
	addTextToSet("Sebastian Daeke");
	addTextToSet("Jelle van Es");

	addTextToSet(" ");
	addTextToSet(" ");

	addTextToSet("Special thanks to");
	addTextToSet(" ");
	addTextToSet("Bob");

}

void CreditScreen::addTextToSet(string message)
{
	textList.push_back(TextureFactory::GenerateText(message, 40, 600, startY, FontEnum::CARTOON));
	startY += 50;
}

CreditScreen::~CreditScreen()
{
	for (auto& i : textList) {
		SDL_DestroyTexture(i.first);
		i.first = nullptr;
	}
	textList.clear();
}

void CreditScreen::resetTextSet()
{
	startY = 650;
	for (auto& i : textList) {
		i.second.y = startY;
		startY += 50;
	}

}

void CreditScreen::Update(float dt)
{

	SDL_Rect last = {};
	for (auto& i : textList) {
		i.second.y -= 1;
		last = i.second;
	}

	if (last.y < -50) {
		resetTextSet();
	}

}

void CreditScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);

	drawText(ren);
}

void CreditScreen::drawText(SDL_Renderer& ren)
{
	for (auto& i : textList) {
		SDL_RenderCopy(&ren, i.first, NULL, &i.second);
	}

}
