#pragma once
#include <vector>
#include "AbstractScreen.h"

class MenuScreen 
	: public AbstractScreen
{
public:
	MenuScreen();
	MenuScreen(SDL_Renderer* ren);//Constructor
	virtual ~MenuScreen();//Destructor
	
	virtual void Update(float dt) = 0;
	virtual void Draw(SDL_Renderer& ren, float dt) = 0;
};