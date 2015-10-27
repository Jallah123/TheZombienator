#include "AbstractScreen.h"
#include <iostream>


AbstractScreen::AbstractScreen(SDL_Renderer* ren)
{
}


AbstractScreen::~AbstractScreen()
{
	std::cout << "Calling AbstractScreen destructor" << std::endl;
	for each (auto component in UIComponents)
	{
		delete component;
	}
	UIComponents.clear();
}
