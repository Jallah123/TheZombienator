#pragma once
#include "Button.h"
#include <iostream>

class LoadingScreen;
class MiniGameButton : public Button
{
	private:
		LoadingScreen* ls = nullptr;
		SDL_Rect spawnRect = { 0, 0, 900, 600 };
	public:
		MiniGameButton();
		MiniGameButton(SDL_Renderer& ren, char* text, char* img_url, LoadingScreen* ls);
		~MiniGameButton();
		void ChangePos();
		virtual void ClickAction() override;
};
