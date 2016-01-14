#include "SaveGameScreen.h"
#include "SaveGameButton.h"

SaveGameScreen::SaveGameScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	SaveGameButton* lsb = new SaveGameButton(*ren, "Save slot 0", "assets/images/button_spritesheet.png", 0);
	SaveGameButton* lsb2 = new SaveGameButton(*ren, "Save slot 1", "assets/images/button_spritesheet.png", 1);
	SaveGameButton* lsb3 = new SaveGameButton(*ren, "Save slot 2", "assets/images/button_spritesheet.png", 2);
	AddUIComponent(lsb);
	AddUIComponent(lsb2);
	AddUIComponent(lsb3);
}

void SaveGameScreen::Update(float dt)
{

}

void SaveGameScreen::Draw(SDL_Renderer & ren, float dt)
{
	AbstractScreen::Draw(ren, dt);
}


SaveGameScreen::~SaveGameScreen()
{
}
