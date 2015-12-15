#pragma once
#include <SDL_image.h>
#include <string>
#include "Character.h"
#include "TextureFactory.h"

class Character;
class BubbleVisitor
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* bubbleImage;
public:
	BubbleVisitor() {};
	BubbleVisitor(SDL_Renderer* _renderer);
	void Visit(Character* character);
	~BubbleVisitor();
};

