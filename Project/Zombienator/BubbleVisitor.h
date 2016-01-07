#pragma once
#include "Image.h"
#include <string>
#include <SDL_image.h>

class Character;
class BubbleVisitor
{
	private:
		SDL_Renderer* ren = nullptr;
		std::pair<SDL_Texture*, SDL_Rect> text;
		SDL_Texture* bubbleImage = nullptr;

		int posX = 0, posY = 0, bubbleHeight = 207, bubbleWidth = 90;

	public:
		BubbleVisitor();
		BubbleVisitor(SDL_Renderer* ren);
		~BubbleVisitor();

		void Visit(Character* c);
		void ChangeText(std::string s);
};

