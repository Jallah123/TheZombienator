#include "Button.h"
#include <iostream>
#include "string"
#include "MenuScreen.h"
#include "TestScreen.h"
#include "ScreenController.h"
#include "Program.h"
#include "SDL_image.h"

Button::Button(SDL_Renderer& ren, std::string text, std::string img_url) : AbstractUIComponent(ren) {
	TTF_Font* Sans = TTF_OpenFont("C:/Users/Tojba/Documents/TheZombienator/Project/Zombienator/Debug/Block-Cartoon.ttf", 1024);
	SDL_Color Black = { 0, 0, 0 };
	char tab2[1024];
	SDL_Surface *s = IMG_Load(strcpy(tab2, img_url.c_str()));

	Image = SDL_CreateTextureFromSurface(&ren, s);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, strcpy(tab2, text.c_str()), Black);
	Message = SDL_CreateTextureFromSurface(&ren, surfaceMessage);
}

void Button::Draw(SDL_Renderer& ren) {
	//TODO color
	SDL_SetRenderDrawColor(&ren, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(&ren, this);
	SDL_RenderCopy(&ren, Image, 0, this);
	SDL_RenderCopy(&ren, Message, 0, this);
}

void Button::ClickAction() {
	std::cout << "Clicked" << std::endl;
	SDL_Renderer* ren = Program::shared_program()->GetRenderer();
	MenuScreen m = TestScreen{ ren };
	ScreenController::GetInstance().ChangeMenu(m);
}

Button::~Button()
{
}
