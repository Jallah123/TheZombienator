#include "Program.h"
#include "SDL_TTF.h"
#include "LoadingScreen.h"
#include "ScreenFactory.h"
#include "GameScreen.h"
#include "GameOverScreen.h"

Program::Program() {
	cout << "Creating Program" << endl;

	if (InitComponents() == 0) {
		cout << "Init complete" << endl;
	}
	if (InitJoystick() == 0) {
		cout << "Init joystick" << endl;
	}

	//init fps
	this->InitFPS();
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

void Program::ShowLoadingScreen() {
	if (ScreenController::GetInstance().GetLoadingScreen() == nullptr)
	{
		LoadingScreen* l = dynamic_cast<LoadingScreen*>(ScreenFactory::Create(ScreenEnum::LOADINGSCREEN));
		ScreenController::GetInstance().AddLoadingScreen(l);
	}

	// SDL Render
	SDL_SetRenderDrawColor(Sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(Sdl_Renderer);
	ScreenController::GetInstance().GetLoadingScreen()->Draw(*Sdl_Renderer, 0);
	// Update screen 
	SDL_RenderPresent(Sdl_Renderer);

	// Sleep
	SDL_Delay(400);
}

void Program::ShowGameOverScreen()
{
	ScreenController::GetInstance().Back();
	ScreenController::GetInstance().ChangeScreen(ScreenFactory::Create(ScreenEnum::GAMEOVERSCREEN));
}

SDL_Renderer* Program::GetRenderer() {
	return Sdl_Renderer;
}

int Program::Tick() {
	gameState = GameState::RUNNING;
	ScreenController* sc = &ScreenController::GetInstance();

	// LoadingScreen
	ShowLoadingScreen();

	// MenuScreen
	MenuScreen* m = dynamic_cast<HomeScreen*>(ScreenFactory::Create(ScreenEnum::HOMESCREEN));
	ScreenController::GetInstance().ChangeScreen(m);
	currentFrameTime = SDL_GetTicks();

	AbstractScreen * previousScreen = sc->GetCurrentScreen();
	AbstractScreen * currentScreen = nullptr;

	while (gameState == GameState::RUNNING) {
		// Calculate DeltaTime
		lastFrameTime = currentFrameTime;
		currentFrameTime = SDL_GetTicks();
		deltaTime = float(currentFrameTime - lastFrameTime) / 10;

		// Handle events on queue 
		while (SDL_PollEvent(&e) != 0) {
			Events(currentScreen);
		}

		// Get currentScreen
		currentScreen = sc->GetCurrentScreen();

		// Check Gameover
		if (GameScreen* g = dynamic_cast<GameScreen*>(currentScreen))
		{
			if (g->IsGameOver())
			{
				ShowGameOverScreen();
				currentScreen = sc->GetCurrentScreen();
			}
		}

		// Check if screen has changed
		if (previousScreen != currentScreen) {
			ShowLoadingScreen();
		}

		// Update & render currentScreen
		currentScreen->setFPS(this->CalculateFPS());
		currentScreen->Update(deltaTime);
		Render(sc->GetCurrentScreen());

		// Update previousScreen
		previousScreen = currentScreen;

		// Update screen 
		SDL_RenderPresent(Sdl_Renderer);
	}

	return 0;
}

void Program::InitFPS()
{
	// Set all frame times to 0ms.
	memset(frametimes, 0, sizeof(frametimes));
	framecount = 0;
	framespersecond = 0;
	frametimelast = SDL_GetTicks();
}

int Program::CalculateFPS()
{
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;

	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = framecount % FRAME_VALUES;

	// store the current time
	getticks = SDL_GetTicks();

	// save the frame time value
	frametimes[frametimesindex] = getticks - frametimelast;

	// save the last frame time for the next fpsthink
	frametimelast = getticks;

	// increment the frame count
	framecount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (framecount < FRAME_VALUES) {

		count = framecount;

	}
	else {

		count = FRAME_VALUES;

	}

	// add up all the values and divide to get the average frame time.
	framespersecond = 0;
	for (i = 0; i < count; i++) {

		framespersecond += frametimes[i];

	}

	framespersecond /= count;

	// now to make it an actual frames per second value...
	framespersecond = 1000.f / framespersecond;

	return framespersecond;
}

void Program::Render(AbstractScreen* screen)
{
	SDL_SetRenderDrawColor(Sdl_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Sdl_Renderer);
	if (screen != nullptr)
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
	else if (e.type == SDL_CONTROLLERAXISMOTION) {
		controllerInputHandler->SetAxis(e.caxis, SDL_RELEASED);
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


	if (TTF_Init() == -1) {
		cerr << "Error loading Open_TTF : " << SDL_GetError() << endl;
		return 1;
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