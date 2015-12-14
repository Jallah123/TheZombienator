#include "HelpScreen.h"
#include "BackButton.h"

HelpScreen::HelpScreen(SDL_Renderer * ren) : MenuScreen(ren)
{
	ChangeBackground(ren, "assets/images/help_bg.png");
	backButton = new BackButton(*ren, "", "assets/images/button_spritesheet.png");
	AddUIComponent(backButton);
}

HelpScreen::~HelpScreen()
{
}

void HelpScreen::Update(float dt)
{
}

void HelpScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
}
