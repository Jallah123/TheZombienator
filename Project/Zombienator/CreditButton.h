#pragma once
#include "Button.h"
class CreditButton :
	public Button
{
public:
	CreditButton();
	~CreditButton();
	CreditButton(SDL_Renderer& ren, char* text, char* img_url);

	virtual void ClickAction() override;
};

