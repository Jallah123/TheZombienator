#include "BubbleVisitor.h"
#include "Image.h"

BubbleVisitor::BubbleVisitor(SDL_Renderer* _renderer)
{
	renderer = _renderer;

	bubbleImage = TextureFactory::GenerateTextureFromImgUrl("assets/images/bubble.png");
}

void BubbleVisitor::Visit(Character* character)
{

	SDL_Rect srcRectangle{ 0, 0, 207, 90 };
	SDL_Rect destRectangle{ character->getPosX()- 28, character->getPosY() - 74, 207, 90 };
	
	SDL_RenderCopy(renderer, bubbleImage, &srcRectangle, &destRectangle);

}

BubbleVisitor::~BubbleVisitor()
{
}
