#pragma once
#include "Button.h"
class LoadGameScreenButton :
	public Button
{
public:
	LoadGameScreenButton(SDL_Renderer& ren, char* text, char* img_url);
	virtual void ClickAction() override;
	~LoadGameScreenButton();
};

