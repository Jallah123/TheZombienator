#include "BubbleVisitor.h"
#include "Image.h"

BubbleVisitor::BubbleVisitor() {}
BubbleVisitor::BubbleVisitor(SDL_Renderer* r) : ren(r), bubbleImage(TextureFactory::GenerateTextureFromImgUrl("assets/images/tutorial/bubble.png")) { ChangeText(" "); }
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

// -- TODO
	// -- Animate Txt?
void BubbleVisitor::ChangeText(string s)
{
	if (text.first != nullptr) // -- Avoid Memory Leaks
		SDL_DestroyTexture(text.first);
	text = TextureFactory::GenerateText(string(s), 14, posX + 14, posY + 8, FontEnum::OCR, { 0, 0, 0 }, 180);
}
