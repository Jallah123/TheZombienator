#pragma once
#include "Button.h"

class SettingsButton
	: public Button
{
public:
	SettingsButton();
	SettingsButton(SDL_Renderer& ren, char* text, char* img_url);
	~SettingsButton();

	virtual void ClickAction() override;
};
