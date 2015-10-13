#include "InfiniteModeButton.h"
#include "string"
#include "MenuScreen.h"
#include "HomeScreen.h"
#include "ScreenController.h"
#include "Program.h"
#include "SDL_image.h"
#include "SDL.h"

InfiniteModeButton::InfiniteModeButton(SDL_Renderer& ren, std::string text, std::string img_url) : AbstractUIComponent(ren) {
	TTF_Font* BlockCartoon = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 16);
	SDL_Color White = { 255, 255, 255 };
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));

	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(BlockCartoon, strcpy(tab2, text.c_str()), White);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
}

void InfiniteModeButton::Draw(SDL_Renderer& ren) {

	// Click Hitbox  
	/*
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&ren, this);
	*/

	// Spritesheet Position
	SDL_Rect srcrect;
	srcrect.x = 0; srcrect.y = 238; srcrect.w = 238; srcrect.h = 102;

	// Screen Position
	SDL_Rect dstrect;
	dstrect.x = 515; dstrect.y = 322; dstrect.w = 238; dstrect.h = 102;

	// --
	SDL_RenderCopy(&ren, Image, &srcrect, &dstrect);

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 530;  //controls the rect's x coordinate 
	Message_rect.y = 358; // controls the rect's y coordinte
	Message_rect.w = 208; // controls the width of the rect
	Message_rect.h = 23; // controls the height of the rect

	SDL_RenderCopy(&ren, Message, nullptr, &Message_rect);
}

void InfiniteModeButton::ClickAction()
{
	std::cout << "InfiniteModeButton Clicked!" << std::endl;
}

InfiniteModeButton::~InfiniteModeButton() {}
