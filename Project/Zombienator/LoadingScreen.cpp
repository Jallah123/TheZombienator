#pragma once
#include "LoadingScreen.h"
#include "ContinueButton.h"

LoadingScreen::LoadingScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	ChangeBackground(ren, "assets/images/bg/loading_bg.png");
	
	// Buttons
	ContinueButton* btnBack = new ContinueButton(*ren, "", "assets/images/button_backtomenu.png");
	AddUIComponent(btnBack);
}

LoadingScreen::~LoadingScreen() {}
void LoadingScreen::Update(float dt) {}
