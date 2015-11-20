#pragma once
#include "Image.h"
#include "TextureFactory.h"

Image::Image(SDL_Renderer& ren, char* img_url) 
	: AbstractUIComponent(ren) {
	
	texture = TextureFactory::GenerateTextureFromImgUrl(img_url);
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
