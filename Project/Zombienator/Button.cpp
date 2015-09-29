#include "Button.h"
#include <iostream>
#include "string"
#include "SDL_ttf.h"

Button::Button(SDL_Renderer& ren, std::string text) : AbstractUIComponent(ren) {
	TTF_Font* Sans = TTF_OpenFont("C:/Users/jelle/Documents/TheZombienator/Project/Zombienator/Debug/sans.ttf", 14);
	SDL_Color Black = { 0, 0, 0 };
	char tab2[1024];
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, strcpy(tab2, text.c_str()), Black);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
}

void Button::Draw(SDL_Renderer& ren) {
	//TODO color
	SDL_SetRenderDrawColor(&ren, 0xFF, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(&ren, this);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void Button::ClickAction() {
	std::cout << "Clicked" << std::endl;
}

Button::~Button()
{
}
