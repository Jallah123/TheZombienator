#include "LabelEndScreen.h"
#include "TextureFactory.h"

LabelEndScreen::LabelEndScreen() : AbstractUIComponent() {}

LabelEndScreen::LabelEndScreen(SDL_Renderer& ren, std::string text, int posX, int posY) : AbstractUIComponent(ren), x(posX), y(posY) {
	label = TextureFactory::GenerateText(text, 19, posX, posY, FontEnum::OCR, { 255,255,255 });
}

LabelEndScreen::~LabelEndScreen() {}

void LabelEndScreen::Draw(SDL_Renderer& ren) {
	SDL_RenderCopy(&ren, label.first, nullptr, &label.second);
}

void LabelEndScreen::ClickAction() {}

void LabelEndScreen::ChangeText(std::string s)
{
	if (label.first != nullptr)
		SDL_DestroyTexture(label.first);
	label = TextureFactory::GenerateText(string(s), 19, x, y, FontEnum::OCR, { 255,255,255 });

}