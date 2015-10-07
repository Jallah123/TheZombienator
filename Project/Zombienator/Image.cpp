#include "Image.h"
#include "string"
#include "MenuScreen.h"
#include "TestScreen.h"
#include "ScreenController.h"
#include "Program.h"
#include "SDL_image.h"
#include "SDL.h"

Image::Image(SDL_Renderer& ren, std::string img_url) : AbstractUIComponent(ren) {
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	Background = SDL_CreateTextureFromSurface(&ren, s);
}

void Image::Draw(SDL_Renderer& ren) {
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderCopy(&ren, Background, 0, this);
}

void Image::ClickAction() {

}

Image::~Image()
{
}
