#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "HomeScreen.h"
#include "TestScreen.h"
#include "SDL_ttf.h"
#include "ScreenController.h"
#include "MapRender.h"
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

	void xmlParseTest();
	int width = 1280;
	int height = 640;

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