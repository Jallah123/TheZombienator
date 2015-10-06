#include "TestScreen.h"
#include <iostream>
#include <random>
#include <time.h>
#include "Button.h"
#include "BackButton.h"

TestScreen::TestScreen(SDL_Renderer* ren) : MenuScreen(ren)
{
	ChangeBackground(ren, "assets/images/menu_preview.png");
	std::cout << "Made TestSCreen" << std::endl;
	Button* b = new Button(*ren, "testkop", "assets/images/menu_bg.png");
	srand(time(NULL));
	int x = rand() % 500 + 150;
	b->SetDimensions(x, 10, 75, 75);
	AddUIComponent(b);
	BackButton* bb = new BackButton(*ren, "Back", "assets/images/menu_bg.png");
	bb->SetDimensions(10, 10, 75, 75);
	AddUIComponent(bb);
}

TestScreen::~TestScreen()
{
}
