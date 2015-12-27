#pragma once
#include "Button.h"
class MultiplayerButton :
	public Button
{
public:
	MultiplayerButton();
	MultiplayerButton(SDL_Renderer& ren, char* text, char* img_url);
	~MultiplayerButton();
	virtual void ClickAction() override;
};