#include "Label.h"
#include "SDL.h"
#include "TextureFactory.h"

Label::Label() : AbstractUIComponent()
{
}

Label::Label(SDL_Renderer& ren, char* text, int posX, int posY, int fontSize, std::string fontUrl, SDL_Color color) : AbstractUIComponent(ren) {
	label = TextureFactory::GenerateText(text, fontSize, posX, posY, fontUrl, color);
}

Label::~Label()
{
}

void Label::Draw(SDL_Renderer& ren) {
	SDL_RenderCopy(&ren, label.first, NULL, &label.second);
}

void Label::ClickAction() {
}

