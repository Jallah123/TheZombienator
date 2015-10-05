#include "TestScreen.h"
#include <iostream>
#include <random>
#include <time.h>

TestScreen::TestScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	ChangeBackground(ren, "assets/images/menu_preview.png");
	std::cout << "Made TestSCreen" << std::endl;
	Button* b = new Button(*ren, "testkop", "assets/images/menu_bg.png");
	srand(time(NULL));
	int x = rand() % 50 + 1;
	int y = rand() % 50 + 1;
	b->SetDimensions(x, y, 75, 75);
	AddUIComponent(b);
}

TestScreen::~TestScreen()
{
}
