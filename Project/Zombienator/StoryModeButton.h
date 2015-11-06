#pragma once
#include "Button.h"

class StoryModeButton 
	: public Button
{
public:
	StoryModeButton();
	StoryModeButton(SDL_Renderer& ren, char* text, char* img_url);
	~StoryModeButton();

	virtual void ClickAction() override;
};
