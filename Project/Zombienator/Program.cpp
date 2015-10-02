#include "Program.h"

Program::Program() {
	if (InitComponents() == 0) {
		cout << "Init complete" << endl;
	}
	if (Render() == 0) {
		cout << "Done rendering" << endl;
	}
}


Program* Program::instance{ nullptr }; // definition & init

Program* Program::shared_program() {

	if (instance == nullptr) {

		instance = new Program;

		return instance;

	}
}



SDL_Renderer* Program::GetRenderer() {
	return Sdl_Renderer;
}

int Program::Render() {
	bool quit = false;
	MenuScreen m = TestScreen{ Sdl_Renderer };
	ScreenController::GetInstance().ChangeMenu(m);
	while (!quit) {
		//Handle events on queue 
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit 
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_Point p = SDL_Point{};
				p.x = e.button.x;
				p.y = e.button.y;
				ScreenController::GetInstance().GetCurrentMenu().ClickComponents(p);
				MenuScreen m = TestScreen{ Sdl_Renderer };
				ScreenController::GetInstance().ChangeMenu(m);
			}
		}


		SDL_SetRenderDrawColor(Sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Sdl_Renderer);
		ScreenController::GetInstance().GetCurrentMenu().Draw(*Sdl_Renderer);

		//Update screen 
		SDL_RenderPresent(Sdl_Renderer);
	}

	SDL_DestroyRenderer(Sdl_Renderer);
	SDL_DestroyWindow(Sdl_Window);
	SDL_Quit();
	return 0;
}

int Program::InitComponents() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "SDL_Init error: " << SDL_GetError() << endl;
		return 1;
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		return 2;
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cout << "SDL_Mixer Error: " << Mix_GetError() << endl;
	}

	// More channels so we can play more sounds at the same time
	Mix_AllocateChannels(16);

	Sdl_Window = SDL_CreateWindow("Zombienator!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, SDL_WINDOW_SHOWN);
	if (Sdl_Window == nullptr) {
		cout << "SDL_CreateWindow error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	Sdl_Renderer = SDL_CreateRenderer(Sdl_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Sdl_Renderer == nullptr) {
		SDL_DestroyWindow(Sdl_Window);
		std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return 0;
}