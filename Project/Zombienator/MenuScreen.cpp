#pragma once
#include "MenuScreen.h"

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/menu_bg.png");
	SoundController->ChangeMusic("assets/sounds/Undead-Rising.wav");
}


MenuScreen::~MenuScreen() 
{ 
}

