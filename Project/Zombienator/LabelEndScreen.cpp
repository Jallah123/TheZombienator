#include "LabelEndScreen.h"
#include "TextureFactory.h"

LabelEndScreen::LabelEndScreen() : AbstractUIComponent() {}

LabelEndScreen::LabelEndScreen(SDL_Renderer& ren, std::string text, int posX, int posY) : AbstractUIComponent(ren) {
	label = TextureFactory::GenerateText(text, 19, posX, posY, FontEnum::OCR, { 255,255,255 });
}

LabelEndScreen::~LabelEndScreen() {}

void LabelEndScreen::Draw(SDL_Renderer& ren) {
	SDL_RenderCopy(&ren, label.first, nullptr, &label.second);
}

void LabelEndScreen::ClickAction() {}