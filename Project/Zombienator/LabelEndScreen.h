#pragma once
#include "AbstractUIComponent.h"
#include <utility>
#include <string>

class LabelEndScreen : public AbstractUIComponent
{
	private:
		int x, y;
	protected:
		std::pair<SDL_Texture*, SDL_Rect> label = {};
	public:
		LabelEndScreen();
		LabelEndScreen(SDL_Renderer& ren, std::string text, int posX, int posY);
		~LabelEndScreen();
		void Draw(SDL_Renderer& ren) override;
		virtual void ClickAction() override;
		void ChangeText(std::string s);
};

