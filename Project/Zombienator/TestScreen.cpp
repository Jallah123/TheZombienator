#include "TestScreen.h"
#include <iostream>

TestScreen::TestScreen(SDL_Renderer& ren) : MenuScreen(ren)
{
	std::cout << "Made TestSCreen" << std::endl;
	Button* b = new Button(ren, "testkop");
	b->SetDimensions(20, 20, 150, 150);
	AddUIComponent(b);
}

TestScreen::~TestScreen()
{
}
