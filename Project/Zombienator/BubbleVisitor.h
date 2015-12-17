#pragma once
#include <SDL_image.h>
#include <string>
#include "Character.h"
#include "TextureFactory.h"

class Character;
class BubbleVisitor
{
	private:
		SDL_Renderer* ren;
		pair<SDL_Texture*, SDL_Rect> text;

		SDL_Texture* bubbleImage;
		int posX, posY, bubbleHeight = 207, bubbleWidth = 90;

	public:
		BubbleVisitor();
		BubbleVisitor(SDL_Renderer* ren);
		~BubbleVisitor();

		void Visit(Character* c);
		void ChangeText(string s);
};

