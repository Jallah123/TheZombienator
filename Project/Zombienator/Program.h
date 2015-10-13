#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "HomeScreen.h"
#include "TestScreen.h"
#include "SDL_ttf.h"
#include "ScreenController.h"

using namespace std;

class Program
{
private:
	SDL_Window* Sdl_Window;
	SDL_Renderer* Sdl_Renderer;
	SDL_Event e;
	TTF_Font* Font;
	int width = 640;
	int height = 1280;

	Program();
	int Render();
	int InitComponents();
public:

	SDL_Renderer* GetRenderer();
	TTF_Font* GetFont();

	static Program& shared_program();
};