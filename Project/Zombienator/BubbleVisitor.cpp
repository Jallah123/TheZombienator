#include "BubbleVisitor.h"
#include "Character.h"
#include "TextureFactory.h"

BubbleVisitor::BubbleVisitor() {}
BubbleVisitor::BubbleVisitor(SDL_Renderer* r) : ren(r), bubbleImage(TextureFactory::CreateTexture("assets/images/tutorial/bubble.png")) { ChangeText(std::string(" ")); }
BubbleVisitor::~BubbleVisitor() {}

void BubbleVisitor::Visit(Character* c)
{
	posX = c->getPosX() - 28;
	posY = c->getPosY() - 78;
	
	SDL_Rect srcRectangle { 0, 0, bubbleHeight, bubbleWidth };
	SDL_Rect destRectangle { posX, posY, bubbleHeight, bubbleWidth };

	SDL_RenderCopy(ren, bubbleImage, &srcRectangle, &destRectangle);
	SDL_RenderCopy(ren, text.first, nullptr, &text.second);

}

void BubbleVisitor::ChangeText(std::string s)
{
	if (text.first != nullptr) // -- Avoid Memory Leaks
		SDL_DestroyTexture(text.first);
	text = TextureFactory::GenerateText(string(s), 14, posX + 16, posY + 10, FontEnum::OCR, { 0, 0, 0 }, 180);

}