#pragma once
#include "MenuScreen.h"
#include <SDL_image.h>
#include "TextureFactory.h"
#include <iostream>

SDL_Texture* texture = nullptr;

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	BackgroundTexture = TextureFactory::GenerateTexture("assets/images/menu_bg.png");

	musicController->Load("assets/sounds/Undead-Rising.wav");
	musicController->Play(1, -1);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, char* img_url)
{
	SDL_Surface *s = IMG_Load(img_url);
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
}


MenuScreen::~MenuScreen() 
{ 
	SDL_DestroyTexture(BackgroundTexture);
	BackgroundTexture = NULL;
}
