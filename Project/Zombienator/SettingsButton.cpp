#include "SettingsButton.h"
#include "string"
#include "MenuScreen.h"
#include "HomeScreen.h"
#include "ScreenController.h"
#include "Program.h"
#include "SDL_image.h"
#include "SDL.h"

SettingsButton::SettingsButton(SDL_Renderer& ren, std::string text, std::string img_url) : AbstractUIComponent(ren) {
	TTF_Font* BlockCartoon = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 1024);
	SDL_Color White = { 255, 255, 255 };
	char tab2[1024];

	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_FreeSurface(s);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(BlockCartoon, strcpy(tab2, text.c_str()), White);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);

	SDL_FreeSurface(surfaceMessage);
	TTF_CloseFont(BlockCartoon);
	BlockCartoon = NULL;
}

void SettingsButton::Draw(SDL_Renderer& ren) {

	// Click Hitbox  
	/*
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&ren, this);
	*/

	// Spritesheet Position
	SDL_Rect srcrect;
	srcrect.x = 286; srcrect.y = 0; srcrect.w = 82;	srcrect.h = 81;

	// Screen Position
	SDL_Rect dstrect;
	dstrect.x = 1189; dstrect.y = 12; dstrect.w = 82; dstrect.h = 81;

	// --
	SDL_RenderCopy(&ren, Image, &srcrect, &dstrect);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void SettingsButton::ClickAction() 
{
	std::cout << "SettingsButton Clicked!" << std::endl;
}

SettingsButton::~SettingsButton() 
{
}
