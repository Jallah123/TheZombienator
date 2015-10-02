#pragma once
#include "MenuScreen.h"
#include "Button.h"
class TestScreen :
	public MenuScreen
{
public:
	TestScreen(SDL_Renderer* ren);
	~TestScreen();
};

