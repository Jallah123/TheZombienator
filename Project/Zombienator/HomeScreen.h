#pragma once
#include "MenuScreen.h"
class SettingsButton;
class StoryModeButton;
class InfiniteModeButton;
class CreditButton;
class MultiplayerButton;
struct HelpButton;

class HomeScreen :
	public MenuScreen
{
private:
	HelpButton* helpBtn = nullptr;
	SettingsButton* settingsBtn = nullptr;
	StoryModeButton* storyModeBtn = nullptr;
	InfiniteModeButton* infiniteModeBtn = nullptr;
	MultiplayerButton* multiplayerBtn = nullptr;
	CreditButton* creditsButton = nullptr;
public:
	HomeScreen(SDL_Renderer* ren);
	~HomeScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	virtual void ReceiveFocus() override;
};

