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
	AddUIComponent(a);

	// StoryModeButton
	StoryModeButton* b = new StoryModeButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(b);

	// StoryModeButton
	InfiniteModeButton* c = new InfiniteModeButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(c);
}

HomeScreen::~HomeScreen()
{
}

void HomeScreen::Update(float dt)
{
}

void HomeScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
}
