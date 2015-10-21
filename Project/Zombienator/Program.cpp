#include "Program.h"
#include "SelectionScreen.h"

Program::Program() {
	cout << "Creating Program" << endl;
	if (InitComponents() == 0) {
		cout << "Init complete" << endl;
	}
	if (InitJoystick() == 0) {
		cout << "Init joystick" << endl;
	}
	if (Render() == 0) {
		cout << "Done rendering" << endl;
	} 
}

Program& Program::shared_program() {
	static Program instance;
	return instance;
}

SDL_Renderer* Program::GetRenderer() {
	return Sdl_Renderer;
}

TTF_Font * Program::GetFont() {
	return Font;
}

int Program::Render() {
	bool quit = false;
	MenuScreen m = HomeScreen{ Sdl_Renderer };
	//MenuScreen m = TestScreen{ Sdl_Renderer };

	ScreenController::GetInstance().ChangeMenu(m);

	// --- //
	currentFrameTime = SDL_GetTicks();
	// --- //

	while (!quit) {
		//Handle events on queue 
		while (SDL_PollEvent(&e) != 0) {

			// --- //
			lastFrameTime = currentFrameTime;
			currentFrameTime = SDL_GetTicks();
			deltaTime = float(currentFrameTime - lastFrameTime) / 1000;
			// --- //



			//User requests quit 
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_Point p = SDL_Point{};
				p.x = e.button.x;
				p.y = e.button.y;
				ScreenController::GetInstance().GetCurrentMenu().ClickComponents(p);
			}
			else if (e.type == SDL_KEYDOWN) {
				keyboardInputHandler->SetKey(e.key.keysym.sym, SDL_PRESSED);
			}
			else if (e.type == SDL_KEYUP) {
				keyboardInputHandler->SetKey(e.key.keysym.sym, SDL_RELEASED);
			}
			else if (e.type == SDL_CONTROLLERBUTTONDOWN) {
				controllerInputHandler->SetButton(e.cbutton, SDL_PRESSED);
			}
			else if (e.type == SDL_CONTROLLERBUTTONUP) {
				controllerInputHandler->SetButton(e.cbutton, SDL_RELEASED);
			}
		}

		SDL_SetRenderDrawColor(Sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Sdl_Renderer);
		ScreenController::GetInstance().GetCurrentMenu().Draw(*Sdl_Renderer , deltaTime);

		//Update screen 
		SDL_RenderPresent(Sdl_Renderer);
	}


	return 0;
}

int Program::InitComponents() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
		cerr << "SDL_Init error: " << SDL_GetError() << endl;
		return 1;
	}
	if (TTF_Init() == -1) {
		cerr << "TTF_Init: %s\n" << TTF_GetError() << endl;
		return 2;
	}
	Font = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 1024);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cerr << "SDL_Mixer Error: " << Mix_GetError() << endl;
	}

	// More channels so we can play more sounds at the same time
	Mix_AllocateChannels(16);

	Sdl_Window = SDL_CreateWindow("Zombienator!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);
	if (Sdl_Window == nullptr) {
		cerr << "SDL_CreateWindow error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	Sdl_Renderer = SDL_CreateRenderer(Sdl_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Sdl_Renderer == nullptr) {
		SDL_DestroyWindow(Sdl_Window);
		cerr << "SDL_CreateRenderer error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}
	keyboardInputHandler = &KeyboardInputHandler::GetInstance();
	controllerInputHandler = &ControllerInputHandler::GetInstance();
	return 0;
}

int Program::InitJoystick() {
	for (int JoystickIndex = 0; JoystickIndex < SDL_NumJoysticks(); ++JoystickIndex)
	{
		if (!SDL_IsGameController(JoystickIndex))
		{
			continue;
		}
		controller = SDL_GameControllerOpen(JoystickIndex);
	}
	return 0;
}
Program::~Program() {
	SDL_GameControllerClose(controller);
	SDL_DestroyRenderer(Sdl_Renderer);
	SDL_DestroyWindow(Sdl_Window);
	SDL_Quit();
}