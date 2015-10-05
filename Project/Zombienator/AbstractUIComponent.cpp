#include "AbstractUIComponent.h"



AbstractUIComponent::AbstractUIComponent(SDL_Renderer& ren)
{
	instance = &ren;
}


AbstractUIComponent::~AbstractUIComponent()
{
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
