#pragma once
#include <vector>
#include "AbstractScreen.h"

class MenuScreen 
	: public AbstractScreen
{
protected:
	SDL_Texture* BackgroundTexture;
	void ChangeBackground(SDL_Renderer* ren, char* img_url);

public:
	MenuScreen();
	MenuScreen(SDL_Renderer* ren);//Constructor
	virtual ~MenuScreen();//Destructor
	
	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }
	
	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
	
};