#include "CreditScreen.h"
#include <iostream>


CreditScreen::CreditScreen(SDL_Renderer* ren) : MenuScreen(ren)
{	

	// Console Update
	std::cout << "Made CreditSCreen" << std::endl;

	if (TTF_Init() < 0) {
		std::cout << "SDL_TTF Error" << std::endl;
	}

	font = 	TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 24); //this opens a font style and sets a size

	 //Render the text
	 //If there was an error in loading the font 
	if( font == NULL ) { 
		std::cout << "Error loading font" << std::endl;
	}

	//Message = renderText("TTF fonts are cool!", ren);
	//int iW, iH;
	//SDL_QueryTexture(Message, NULL, NULL, &iW, &iH);
	//int x = 1024 / 2 - iW / 2;
	//int y = 800 / 2 - iH / 2;


	SDL_Surface*  message = TTF_RenderText_Solid( font, "Credit screen", fontColor); //If there was an error in rendering the text if( message == NULL ) { return 1; }
	Message = SDL_CreateTextureFromSurface(ren, message); //now you can convert it into a texture
	Message_rect.x = 400;  //controls the rect's x coordinate 
	Message_rect.y = 300; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
}

SDL_Texture* CreditScreen::renderText(const std::string &message, SDL_Renderer *renderer)
{
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), fontColor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	
	return texture;
}


CreditScreen::~CreditScreen()
{
	//Quit SDL_ttf 
	TTF_Quit();
}



void CreditScreen::Update(float dt)
{
}

void CreditScreen::Draw(SDL_Renderer & ren, float dt)
{
	SDL_RenderCopy(&ren, BackgroundTexture, 0, 0);
	for (const auto& i : UIComponents)
		i->Draw(ren);
	SDL_RenderCopy(&ren, Message, NULL,&Message_rect);

}
