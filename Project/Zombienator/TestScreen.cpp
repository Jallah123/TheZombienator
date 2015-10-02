#include "TestScreen.h"
#include <iostream>

TestScreen::TestScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	ChangeBackground(ren, "C:/Users/Tojba/Documents/TheZombienator/Project/Zombienator/Debug/assets/images/menu_preview.png");
	std::cout << "Made TestSCreen" << std::endl;
	Button* b = new Button(*ren, "testkop", "C:/Users/Tojba/Documents/TheZombienator/Project/Zombienator/Debug/assets/images/menu_bg.png");
	b->SetDimensions(20, 20, 75, 75);
	AddUIComponent(b);
}

TestScreen::~TestScreen()
{
}
