#include "MenuScreen.h"
#include <iostream>
#include "SDL_image.h"

SDL_Texture* texture = nullptr;

MenuScreen::MenuScreen(SDL_Renderer* ren) : AbstractScreen(ren)
{
	SDL_Surface *s = IMG_Load("assets/images/menu_bg.png");
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);

	musicController->Load("assets/sounds/Undead-Rising.wav");
	musicController->Play(-1, -1);
}

void MenuScreen::ChangeBackground(SDL_Renderer* ren, std::string img_url)
{
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));
	BackgroundTexture = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
}


MenuScreen::~MenuScreen() 
{
	musicController->Stop();
	SDL_DestroyTexture(BackgroundTexture);
	BackgroundTexture = NULL;
}
