#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"
#include <iostream>

SDL_Texture* texture = nullptr;

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	BackgroundTexture = TextureFactory::GenerateTextureFromImgUrl("assets/images/menu_bg.png");

	musicController->Load("assets/sounds/Undead-Rising.wav");
	musicController->Play(1, -1);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, char* img_url)
{
	BackgroundTexture = TextureFactory::GenerateTextureFromImgUrl(img_url);
}


MenuScreen::~MenuScreen() 
{ 
	SDL_DestroyTexture(BackgroundTexture);
	BackgroundTexture = NULL;
}
