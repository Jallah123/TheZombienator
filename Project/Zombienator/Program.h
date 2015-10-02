#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
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
	int width = 720;
	int height = 1280;

	static Program* instance; // our shared instance

	Program();

	int Render();
	int InitComponents();
public:
	SDL_Renderer* GetRenderer();

	static Program* shared_program();
};