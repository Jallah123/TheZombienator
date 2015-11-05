#include "Button.h"
#include <iostream>
#include "SDL_image.h"
#include "SDL.h"

Button::Button() : AbstractUIComponent()
{
}

Button::Button(SDL_Renderer& ren, char* text, char* img_url) : AbstractUIComponent(ren) {
	SDL_Surface *s = IMG_Load(img_url);
	image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_FreeSurface(s);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
	message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);

	TTF_CloseFont(font);
	font = NULL;
}
Button::~Button()
{
}

void Button::Draw(SDL_Renderer& ren) {

	SDL_RenderCopy(&ren, image, &srcRect, &destRect);
	SDL_RenderCopy(&ren, message, 0, &destRect);
}
