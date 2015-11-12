#include "Program.h"

Program::Program() {
	cout << "Creating Program" << endl;
	if (InitComponents() == 0) {
		cout << "Init complete" << endl;
	}
	if (InitJoystick() == 0) {
		cout << "Init joystick" << endl;
	}
}

Program* Program::instance{ nullptr };

Program* Program::getInstance()
{
	if (instance == nullptr) {
		instance = new Program;
	}
	return instance;
}

/*
Program& Program::shared_program() {
	static Program instance;
	return instance;
}
*/

SDL_Renderer* Program::GetRenderer() {
	return Sdl_Renderer;
}

int Program::Tick() {
	gameState = GameState::RUNNING;
	ScreenController* sc = &ScreenController::GetInstance();

	// MenuScreen
	MenuScreen* m = new HomeScreen{ Sdl_Renderer };
	ScreenController::GetInstance().ChangeScreen(m);
	currentFrameTime = SDL_GetTicks();

	while (gameState == GameState::RUNNING) {
		// Calculate DeltaTime
		lastFrameTime = currentFrameTime;
		currentFrameTime = SDL_GetTicks();
		deltaTime = float(currentFrameTime - lastFrameTime) / 10;

		//Handle events on queue 
		while (SDL_PollEvent(&e) != 0) {
			Events(sc->GetCurrentScreen());
		}
		sc->GetCurrentScreen()->Update(deltaTime);
		Render(sc->GetCurrentScreen());
		//Update screen 
		SDL_RenderPresent(Sdl_Renderer);
	}

	return 0;
}

void Program::Render(AbstractScreen* screen)
{
	SDL_SetRenderDrawColor(Sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(Sdl_Renderer);

	screen->Draw(*Sdl_Renderer, deltaTime);
}

int Program::Events(AbstractScreen* screen)
{
	//User requests quit 
	if (e.type == SDL_QUIT) {
		gameState = GameState::QUIT;
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN) {
		SDL_Point p = SDL_Point{ e.button.x , e.button.y };
		screen->ClickComponents(p);
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
	else if (e.type == SDL_CONTROLLERDEVICEADDED) {
		InitJoystick();
	}
	else if (e.type == SDL_CONTROLLERDEVICEREMOVED) {
		CloseJoystick();
	}
	return 0;
}

int Program::InitComponents() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
		cerr << "SDL_Init error: " << SDL_GetError() << endl;
		return 1;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cerr << "SDL_Mixer Error: " << Mix_GetError() << endl;
	}

	// More channels so we can play more sounds at the same time
	Mix_AllocateChannels(16);

	Sdl_Window = SDL_CreateWindow("Zombienator!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
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

void Program::CloseJoystick() 
{
	cout << "Close controller" << endl;
	SDL_GameControllerClose(controller);
}

int Program::InitJoystick() {
	cout << "Init joystick" << endl;
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