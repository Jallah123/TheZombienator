#include "AbstractScreen.h"
#include <iostream>


AbstractScreen::AbstractScreen(SDL_Renderer* ren)
{
}


AbstractScreen::~AbstractScreen()
{
	std::cout << "Calling base destructor" << std::endl;
	for each (auto component in UIComponents)
	{
		delete component;
	}
	UIComponents.clear();
}
