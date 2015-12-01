#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "HomeScreen.h"
#include "ScreenController.h"
#include "KeyboardInputHandler.h"
#include "ControllerInputHandler.h"
#include "GameState.cpp"
#include "LoadingScreen.h"

class Program
{
private:
	SDL_Window* Sdl_Window = nullptr;
	SDL_Renderer* Sdl_Renderer = nullptr;
	SDL_Event e{ NULL };
	SDL_GameController* controller = nullptr;
	KeyboardInputHandler* keyboardInputHandler = nullptr;
	ControllerInputHandler* controllerInputHandler = nullptr;
	GameState gameState = GameState::INIT;

	int width = 1280;
	int height = 640;

	// DeltaTime
	float deltaTime;
	int lastFrameTime = 0;
	int currentFrameTime = 0;

	//fps
	#define FRAME_VALUES 100
	// An array to store frame times:
	Uint32 frametimes[FRAME_VALUES];
	// Last calculated SDL_GetTicks
	Uint32 frametimelast;
	// total frames rendered
	Uint32 framecount;
	// the value you want
	float framespersecond;
	
	int Tick();
	void Render(AbstractScreen* screen);
	int Events(AbstractScreen* screen);
	int InitComponents();
	int InitJoystick();
	void ShowLoadingScreen();
	void ShowGameOverScreen();
	void CloseJoystick();

	int CalculateFPS();
	void InitFPS();

	static Program* instance;
	Program(Program const&) = delete;
	void operator=(Program const&) = delete;
	Program();
	~Program();
public:
	int Start() { return Tick(); }
	SDL_Renderer* GetRenderer();
	// static Program& shared_program();
	static Program* getInstance();
};