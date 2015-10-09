#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "TestScreen.h"
#include "SDL_ttf.h"
#include "ScreenController.h"
#include "KeyboardInputHandler.h"
#include "ControllerInputHandler.h"

using namespace std;

class Program
{
private:
	SDL_Window* Sdl_Window;
	SDL_Renderer* Sdl_Renderer;
	SDL_Event e;
	SDL_GameController* controller;
	KeyboardInputHandler* keyboardInputHandler;
	ControllerInputHandler* controllerInputHandler;
	TTF_Font* Font;
	int width = 720;
	int height = 1280;

	Program();
	~Program();
	int Render();
	int InitComponents();
	int InitJoystick();
public:

	SDL_Renderer* GetRenderer();
	TTF_Font* GetFont();

	static Program& shared_program();
};