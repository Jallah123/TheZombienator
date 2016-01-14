#pragma once
#include "Button.h"

class LoadSaveButton : public Button
{
private:
	int loadSlot = 0;
public:
	LoadSaveButton(SDL_Renderer& ren, char* text, char* img_url, int _loadSlot);
	virtual void ClickAction() override;
	~LoadSaveButton();
};

