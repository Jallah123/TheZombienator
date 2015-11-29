#include "AbstractUIComponent.h"
#include <iostream>

AbstractUIComponent::AbstractUIComponent()
{
}

AbstractUIComponent::AbstractUIComponent(SDL_Renderer& ren)
{
	renderer = &ren;
}

void AbstractUIComponent::SetDestLocation(int x, int y)
{
	destRect.x = x;
	destRect.y = y;
}

void AbstractUIComponent::SetSourceLocation(int x, int y)
{
	srcRect.x = x;
	srcRect.y = y;
}

void AbstractUIComponent::SetSize(int ww, int hh)
{
	srcRect.w = ww; 
	srcRect.h = hh;

	destRect.w = ww;
	destRect.h = hh;
}

void AbstractUIComponent::OnClick(SDL_Point p)
{
	SDL_Rect MouseRect{ p.x, p.y, 1, 1 };
	if (SDL_HasIntersection(&destRect, &MouseRect) == SDL_TRUE) {
		ClickAction();
	}
}

AbstractUIComponent::~AbstractUIComponent()
{
	if (message != nullptr) {
		SDL_DestroyTexture(message);
	}
	SDL_DestroyTexture(image);
	message = NULL;
	image = NULL;
	renderer = nullptr;
}