#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "TestScreen.h"
#include "Button.h"
#include "SDL_ttf.h"
#include "ScreenController.h"

using namespace std;

SDL_Window *win = nullptr;
SDL_Renderer *ren = nullptr;
SDL_Event e;

Mix_Music* mscMusic = NULL;
Mix_Chunk* sndShot = NULL;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
		return 1;
	}
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		cout << "SDL_Mixer Error: " << Mix_GetError() << endl;
	}

	// More channels so we can play more sounds at the same time
	Mix_AllocateChannels(16);

	win = SDL_CreateWindow("Zombienator!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	//While application is running 
	bool quit = false;
	MenuScreen m = TestScreen{ *ren };
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
				m.ClickComponents(p);
			}
		} //Clear screen 

		
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(ren);
		ScreenController::GetInstance().GetCurrentMenu().Draw(*ren);

		//Update screen 
		SDL_RenderPresent(ren);
	}

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
