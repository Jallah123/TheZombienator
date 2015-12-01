#include "Button.h"
#include <iostream>
#include "SDL.h"
#include "TextureFactory.h"

Button::Button() : AbstractUIComponent()
{
}

Button::Button(SDL_Renderer& ren, char* text, char* img_url) : AbstractUIComponent(ren) {
	image = TextureFactory::GenerateTextureFromImgUrl(img_url);
}
Button::~Button()
{
}

void Button::Draw(SDL_Renderer& ren) {

	SDL_RenderCopy(&ren, image, &srcRect, &destRect);
	if (buttonText.first != nullptr) {
		SDL_RenderCopy(&ren, buttonText.first, NULL, &buttonText.second);
	}
}
