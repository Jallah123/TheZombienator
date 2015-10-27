#pragma once
#include "AbstractUIComponent.h"
#include "string"
#include "SDL.h"

class InfiniteModeButton : public AbstractUIComponent
{
public:
	InfiniteModeButton(SDL_Renderer& ren, std::string text, std::string img_url);
	void Draw(SDL_Renderer & ren);
	void ClickAction();
	~InfiniteModeButton();
};
