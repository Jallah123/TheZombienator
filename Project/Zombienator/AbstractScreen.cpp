#include "AbstractScreen.h"


AbstractScreen::AbstractScreen(SDL_Renderer* ren)
{
}


AbstractScreen::~AbstractScreen()
{
	for each (auto component in UIComponents)
	{
		delete component;
	}
	UIComponents.clear();
}
