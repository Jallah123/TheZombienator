#pragma once
#include "HomeScreen.h"
#include <iostream>
#include "SettingsButton.h"
#include "StoryModeButton.h"
#include "InfiniteModeButton.h"
#include "CreditButton.h"
#include "SettingsButton.h"

HomeScreen::HomeScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	// Console Update
	std::cout << "Made HomeScreen" << std::endl;

	// SettingsButton
	SettingsButton* a = new SettingsButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(a);

	// StoryModeButton
	StoryModeButton* b = new StoryModeButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);

	// InfiniteModeButton -- Uncomment for presentation
	//InfiniteModeButton* c = new InfiniteModeButton(*ren, "", "assets/images/button_spritesheet.png");
	//AddUIComponent(c);

	// CreditScreenButton
	CreditButton* d = new CreditButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(d);
	SoundController->ChangeMusic("assets/sounds/Undead-Rising.flac");
}

void HomeScreen::ReceiveFocus()
{
	SoundController->ChangeMusic("assets/sounds/Undead-Rising.flac");
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::Update(float dt)
{
}

void HomeScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
