#pragma once
#include "MenuScreen.h"
#include "TextureFactory.h"

SDL_Texture* texture = nullptr;

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	BackgroundTexture = TextureFactory::GenerateTextureFromImgUrl("assets/images/menu_bg.png");

	SoundController->ChangeMusic("assets/sounds/Undead-Rising.wav");
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
