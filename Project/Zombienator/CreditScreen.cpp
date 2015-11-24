#include "CreditScreen.h"
#include <iostream>


CreditScreen::CreditScreen(SDL_Renderer* ren) : MenuScreen(ren)
{	


	// Console Update
	std::cout << "Made CreditSCreen" << std::endl;

	if (TTF_Init() < 0) {
		std::cout << "SDL_TTF Error" << std::endl;
	}

	font = 	TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 40); //this opens a font style and sets a size

	 //If there was an error in loading the font 
	if( font == NULL ) { 
		std::cout << "Error loading font" << std::endl;
	}
	

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
	SDL_Surface * surface = TTF_RenderText_Blended(font, message.c_str(), fontColor);
	if (surface)
	{
		SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(ren, surface);
		SDL_Rect messageRectange = { 600 - (surface->w / 2), startY - (surface->h / 2), surface->w, surface->h };
		textSet[messageTexture] = messageRectange;

		startY += 50;
	}
}



CreditScreen::~CreditScreen()
{
	//Quit SDL_ttf 
	TTF_Quit();
}

void CreditScreen::resetTextSet()
{
	startY = 650;
	typedef map<SDL_Texture*, SDL_Rect>::iterator it_type;
	for (it_type it = textSet.begin(); it != textSet.end(); it++) {
		it->second.y = startY;
		startY += 50;
	}
}

void CreditScreen::Update(float dt)
{
	typedef map<SDL_Texture*, SDL_Rect>::iterator it_type;
	for (it_type iterator = textSet.begin(); iterator != textSet.end(); iterator++) {
		iterator->second.y -= 1;
		if (iterator == --textSet.end()) {
			if (iterator->second.y < -50) {
				resetTextSet();
			}
		}
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
	typedef map<SDL_Texture*, SDL_Rect>::iterator it_type;
	for (it_type iterator = textSet.begin(); iterator != textSet.end(); iterator++) {
		SDL_RenderCopy(&ren, iterator->first, NULL, &iterator->second);
	}
}
