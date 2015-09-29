#include "TestScreen.h"
#include <iostream>

TestScreen::TestScreen(SDL_Renderer& ren) : MenuScreen(ren)
{
	std::cout << "Made TestSCreen" << std::endl;
}


TestScreen::~TestScreen()
{
}
