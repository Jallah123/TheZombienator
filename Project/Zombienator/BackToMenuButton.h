#pragma once
#include "Button.h"

#include <iostream>

class BackToMenuButton
	: public Button
{
public:
	BackToMenuButton();
	BackToMenuButton(SDL_Renderer& ren, char* text, char* img_url);
	~BackToMenuButton();
	virtual void ClickAction() override;
};
