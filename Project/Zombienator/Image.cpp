#pragma once
#include "Image.h"
#include "TextureFactory.h"

Image::Image(SDL_Renderer& ren, string _img_url) 
	: AbstractUIComponent(ren) {
	img_url = _img_url;
	texture = TextureFactory::CreateTexture(img_url);
}

void Image::Draw(SDL_Renderer& ren) {
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderCopy(&ren, texture, &srcRect, &destRect);
}

void Image::ClickAction() {

}

Image::~Image()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
}
