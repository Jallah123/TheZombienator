#include "BackButton.h"
#include "ScreenController.h"
#include "SDL_image.h"

BackButton::BackButton(SDL_Renderer& ren, std::string text, std::string img_url) : AbstractUIComponent(ren) {
	// TODO: When singleton is working correctly, uncomment.
	// TTF_Font* Sans = Program::shared_program()->GetFont();
	TTF_Font* Sans = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 1024);
	SDL_Color Black = { 0, 0, 0 };
	char tab2[1024];
	const char* url = img_url.c_str();
	
	SDL_Surface *s = IMG_Load(url);

	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, strcpy(tab2, text.c_str()), Black);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
}

void BackButton::Draw(SDL_Renderer& ren) {
	//TODO color
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&ren, this);
	SDL_RenderCopy(&ren, Image, 0, this);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void BackButton::ClickAction() {
	ScreenController::GetInstance().Back();
}

BackButton::~BackButton()
{
}
