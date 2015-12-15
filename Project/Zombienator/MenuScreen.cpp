#pragma once
#include "MenuScreen.h"

MenuScreen::MenuScreen() : AbstractScreen()
{
}

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/bg/menu_bg.png");
}


MenuScreen::~MenuScreen() 
{ 
}

