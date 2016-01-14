#include "LoadGameScreen.h"
#include "LoadSaveButton.h"
#include "BackButton.h"
#include "StoryModeButton.h"

LoadGameScreen::LoadGameScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	BackButton* b = new BackButton(*ren, "", "assets/images/button_spritesheet.png");
	StoryModeButton* smb = new StoryModeButton(*ren, "New Game", "assets/images/button_spritesheet.png");
	LoadSaveButton* lsb = new LoadSaveButton(*ren, "Continue", "assets/images/button_spritesheet.png", 1);
	AddUIComponent(b);
	AddUIComponent(smb);
	AddUIComponent(lsb);
}

void LoadGameScreen::Update(float dt)
{

}

void LoadGameScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
}


LoadGameScreen::~LoadGameScreen()
{
}
