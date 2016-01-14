#pragma once
#include "HomeScreen.h"
#include "SettingsButton.h"
#include "StoryModeButton.h"
#include "InfiniteModeButton.h"
#include "CreditButton.h"
#include "SettingsButton.h"
#include "ScreenController.h"
#include "ScreenFactory.h"
#include "MultiplayerButton.h"

struct HelpButton : Button {

	HelpButton(SDL_Renderer& ren, char* text, char* img_url)
		: Button(ren, text, img_url)
	{
		srcRect = { 286, 240, 82, 81 };
		destRect = { 1190, 174, 82, 81 };
	}

	void ClickAction() {
		ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::LOADGAMESCREEN));
	}
};

HomeScreen::HomeScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	helpBtn = new HelpButton(*ren, "Help", "assets/images/button_spritesheet.png");
	// SettingsButton
	settingsBtn = new SettingsButton(*ren, "", "assets/images/button_spritesheet.png");
	// StoryModeButton
	storyModeBtn = new StoryModeButton(*ren, "Story Mode", "assets/images/button_spritesheet.png");
	// InfiniteModeButton -- Uncomment for presentation
	infiniteModeBtn = new InfiniteModeButton(*ren, "Infinite Mode", "assets/images/button_spritesheet.png");
	// Multiplayer
	multiplayerBtn = new MultiplayerButton(*ren, "Multiplayer", "assets/images/button_spritesheet.png");
	// CreditScreenButton
	creditsButton = new CreditButton(*ren, "", "assets/images/button_spritesheet.png");

	AddUIComponent(storyModeBtn);
	AddUIComponent(infiniteModeBtn);
	AddUIComponent(multiplayerBtn);
	AddUIComponent(settingsBtn);
	AddUIComponent(creditsButton);
	AddUIComponent(helpBtn);
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
	AbstractScreen::Draw(ren, dt);
	SDL_RenderCopy(&ren, backgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
	HandleKeyboardEvents(ren, dt);
}
