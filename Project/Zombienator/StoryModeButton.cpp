#include "StoryModeButton.h"
#include "string"
#include "MenuScreen.h"
#include "HomeScreen.h"
#include "ScreenController.h"
#include "Program.h"
#include "SDL_image.h"
#include "SDL.h"
#include "GameScreen.h"

StoryModeButton::StoryModeButton(SDL_Renderer& ren, std::string text, std::string img_url) : AbstractUIComponent(ren) {
	TTF_Font* BlockCartoon = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 16);
	SDL_Color White = { 255, 255, 255 };
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));

	Sdl_Renderer = &ren;

	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_FreeSurface(s);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(BlockCartoon, strcpy(tab2, text.c_str()), White);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
}

void StoryModeButton::Draw(SDL_Renderer& ren) {

	// Click Hitbox  
	/*
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&ren, this);
	*/

	// Spritesheet Position
	SDL_Rect srcrect;
	srcrect.x = 0; srcrect.y = 340; srcrect.w = 238; srcrect.h = 102;

	// Screen Position
	SDL_Rect dstrect;
	dstrect.x = 515; dstrect.y = 220; dstrect.w = 238; dstrect.h = 102;

	// --
	SDL_RenderCopy(&ren, Image, &srcrect, &dstrect);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void StoryModeButton::ClickAction()
{
	std::cout << "StoryModeButton Clicked!" << std::endl;
	ScreenController::GetInstance().ChangeMenu(new GameScreen{ Sdl_Renderer, "assets/maps/map1-final.json" });
}

StoryModeButton::~StoryModeButton() 
{
}
