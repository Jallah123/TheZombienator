#pragma once
#include "Button.h"

class SaveGameButton : public Button
{
private:
	int loadSlot = 0;
public:
	SaveGameButton(SDL_Renderer& ren, char* text, char* img_url, int _loadSlot);
	virtual void ClickAction() override;
	~SaveGameButton();
};
