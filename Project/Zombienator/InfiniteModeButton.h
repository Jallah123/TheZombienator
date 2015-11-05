#pragma once
#include "Button.h"

class InfiniteModeButton : public Button
{
public:
	InfiniteModeButton();
	InfiniteModeButton(SDL_Renderer& ren, char* text, char* img_url);
	~InfiniteModeButton();

	virtual void ClickAction() override;
};
