/*
#include "PreviousButton.h"
#include "Program.h"
#include "SDL_image.h"
#include "SDL.h"
#include "SelectionScreen.h"
#include "AbstractUIComponent.h"

PreviousButton::PreviousButton(SDL_Renderer& ren, std::string text, std::string img_url, SelectionScreen& ss) : AbstractUIComponent(ren) {
	TTF_Font* Sans = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 1024);
	SDL_Color Black = { 0, 0, 0 };
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));

	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, strcpy(tab2, text.c_str()), Black);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
}

void PreviousButton::Draw(SDL_Renderer& ren) {
	SDL_RenderCopy(&ren, Image, 0, this);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void PreviousButton::ClickAction() {
	std::cout << SelectionScreen->images.capacity() << std::endl;
	SelectionScreen->currentImageIndex--;
	if (SelectionScreen->currentImageIndex < 0)
	{
		SelectionScreen->currentImageIndex = SelectionScreen->images.capacity() - 1;
	}
	std::cout << "ImageIndex: " << SelectionScreen->currentImageIndex << std::endl;
	*SelectionScreen->currentImage = SelectionScreen->images.at(SelectionScreen->currentImageIndex);
}

PreviousButton::~PreviousButton()
{
}
*/