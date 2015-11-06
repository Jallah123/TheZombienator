#pragma once
#include "Image.h"
#include <SDL_image.h>

Image::Image(SDL_Renderer& ren, char* img_url) 
	: AbstractUIComponent(ren) {
	
	SDL_Surface *s = IMG_Load(img_url);
	texture = SDL_CreateTextureFromSurface(&ren, s);
	SDL_FreeSurface(s);
}

void Image::Draw(SDL_Renderer& ren) {
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderCopy(&ren, texture, 0, &srcRect);
}

void Image::ClickAction() {

}

Image::~Image()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}
