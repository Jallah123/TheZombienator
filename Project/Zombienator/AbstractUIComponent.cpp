#include "AbstractUIComponent.h"
#include <iostream>

AbstractUIComponent::AbstractUIComponent(SDL_Renderer& ren)
{
	instance = &ren;
}

void AbstractUIComponent::OnClick(SDL_Point MousePosition)
{
	SDL_Rect MouseRect;
	MouseRect.x = MousePosition.x;
	MouseRect.y = MousePosition.y;
	MouseRect.h = 1;
	MouseRect.w = 1;
	if (SDL_HasIntersection(this, &MouseRect) == SDL_TRUE) {
		ClickAction();
	}
}

AbstractUIComponent::~AbstractUIComponent()
{
	std::cout << "Calling AbstractUIComponent destructor" << std::endl;
	SDL_DestroyTexture(Message);
	SDL_DestroyTexture(Image);
	Message = NULL;
	Image = NULL;
	instance = nullptr;
}