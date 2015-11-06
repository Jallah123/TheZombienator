#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include "HomeScreen.h"
#include "ScreenController.h"
#include "KeyboardInputHandler.h"
#include "ControllerInputHandler.h"
#include "GameState.cpp"

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

	
	int Tick();
	void Render(AbstractScreen* screen);
	int Events(AbstractScreen* screen);
	int InitComponents();
	int InitJoystick();
	void CloseJoystick();

public:
	Program();
	~Program();

	SDL_Renderer* GetRenderer();
	static Program& shared_program();
};