#pragma once
#include "Button.h"
#include "string"
#include "SDL.h"

class StoryModeButton : public Button
{
public:
	StoryModeButton();
	StoryModeButton(SDL_Renderer& ren, char* text, char* img_url);
	
	virtual void ClickAction() override;
	~StoryModeButton();
};
