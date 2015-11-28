#pragma once
#include "Button.h"

class BackButton 
	: public Button
{
public:
	BackButton();
	BackButton(SDL_Renderer& ren, char* text, char* img_url);
	~BackButton();
	virtual void ClickAction() override;
};
