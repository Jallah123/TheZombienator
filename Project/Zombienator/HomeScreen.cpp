#include "HomeScreen.h"
#include <iostream>
#include <random>
#include <time.h>
#include "SettingsButton.h"
#include "StoryModeButton.h"
#include "InfiniteModeButton.h"

HomeScreen::HomeScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	// Console Update
	std::cout << "Made HomeScreen" << std::endl;

	// SettingsButton
	SettingsButton* a = new SettingsButton(*ren, "", "assets/images/button_spritesheet.png");
	a->SetDimensions(1189, 12, 82, 81);
	AddUIComponent(a);

	// StoryModeButton
	StoryModeButton* b = new StoryModeButton(*ren, "", "assets/images/button_spritesheet.png");
	b->SetDimensions(515, 220, 238, 102);
	AddUIComponent(b);

	// StoryModeButton
	InfiniteModeButton* c = new InfiniteModeButton(*ren, "", "assets/images/button_spritesheet.png");
	c->SetDimensions(515, 322, 238, 102);
	AddUIComponent(c);
}

HomeScreen::~HomeScreen()
{
}
