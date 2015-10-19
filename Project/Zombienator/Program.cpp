#include "Program.h"
#include "GameScreen.h"

Program::Program() {
	cout << "Creating Program" << endl;
	if (InitComponents() == 0) {
		cout << "Init complete" << endl;
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

TTF_Font * Program::GetFont()
{
	return Font;
}


int Program::Render() {
	bool quit = false;
	GameScreen* m = new GameScreen{ Sdl_Renderer, "assets/maps/TestMap.json" };
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
				ScreenController::GetInstance().GetCurrentMenu()->ClickComponents(p);
			}
		}

		SDL_SetRenderDrawColor(Sdl_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Sdl_Renderer);
		ScreenController::GetInstance().GetCurrentMenu()->Draw(*Sdl_Renderer);
		// ScreenController& sg = ScreenController::GetInstance();

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

	Sdl_Window = SDL_CreateWindow("Zombienator!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
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
	return 0;
}