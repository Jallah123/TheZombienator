#include "LoadGameScreen.h"
#include "LoadSaveButton.h"

LoadGameScreen::LoadGameScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	LoadSaveButton* lsb = new LoadSaveButton(*ren, "Load slot 0", "assets/images/button_spritesheet.png", 0);
	LoadSaveButton* lsb2 = new LoadSaveButton(*ren, "Load slot 1", "assets/images/button_spritesheet.png", 1);
	LoadSaveButton* lsb3 = new LoadSaveButton(*ren, "Load slot 2", "assets/images/button_spritesheet.png", 2);
	AddUIComponent(lsb);
	AddUIComponent(lsb2);
	AddUIComponent(lsb3);
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
