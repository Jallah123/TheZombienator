#pragma once
#include "Button.h"
#include <iostream>

class ContinueButton : public Button
{
	public:
		ContinueButton();
		ContinueButton(SDL_Renderer& ren, char* text, char* img_url);
		~ContinueButton();
		virtual void ClickAction() override;
};
