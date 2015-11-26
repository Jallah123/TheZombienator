#include "CreditScreen.h"

CreditScreen::CreditScreen(SDL_Renderer* ren) : MenuScreen(ren)
{	


	//plays sound:
	SoundController->ChangeMusic("assets/sounds/StandByMe.wav");


	//Credit text
	addTextToSet("Made by", ren);
	addTextToSet(" ", ren);

	addTextToSet("Sander de Haas", ren);
	addTextToSet("Paul Laros", ren);
	addTextToSet("Kenneth Mauriks", ren);
	addTextToSet("Thomas Reijnders", ren);
	addTextToSet("Sebastian Daeke", ren);
	addTextToSet("Jelle van Es", ren);

	addTextToSet(" ", ren);
	addTextToSet(" ", ren);

	addTextToSet("Special thanks to", ren);
	addTextToSet(" ", ren);
	addTextToSet("Bob", ren);

}

void CreditScreen::addTextToSet(string message, SDL_Renderer* ren)
{
	textList.push_back(TextureFactory::GenerateText(message, *ren, 40, 600, startY));
	startY += 50;
}



CreditScreen::~CreditScreen()
{
	//Quit SDL_ttf 
	TTF_Quit();
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
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
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
