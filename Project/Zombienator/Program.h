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
#include "GameState.cpp"

using namespace std;

class Program
{
private:
	SDL_Window* Sdl_Window = nullptr;
	SDL_Renderer* Sdl_Renderer = nullptr;
	SDL_Event e;
	SDL_GameController* controller = nullptr;
	KeyboardInputHandler* keyboardInputHandler = nullptr;
	ControllerInputHandler* controllerInputHandler = nullptr;
	TTF_Font* Font = nullptr;
	GameState gameState = GameState::INIT;

	void xmlParseTest();
	int width = 1280;
	int height = 640;

	// DeltaTime
	float deltaTime;
	int lastFrameTime = 0;
	int currentFrameTime = 0;

	Program();
	~Program();
	int Tick();
	void Render(AbstractScreen* screen);
	int Events(AbstractScreen* screen);
	int InitComponents();
	int InitJoystick();
	void CloseJoystick();
public:

	SDL_Renderer* GetRenderer();
	TTF_Font* GetFont();

	static Program& shared_program();
};