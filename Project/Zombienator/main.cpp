#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "MenuScreen.h"

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
	while (!quit) {
		//Handle events on queue 
		while (SDL_PollEvent(&e) != 0) {
			//User requests quit 
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				cout << "Clicked position: " << e.button.x << ":" << e.button.y << endl;
			}
		} //Clear screen 

		

		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0x00, 0xFF);
		//Render texture to screen 
		SDL_Rect rectangle;
		rectangle.x = 10;
		rectangle.y = 10;
		rectangle.w = 50;
		rectangle.h = 50;

		SDL_RenderFillRect(ren, &rectangle);
		//Update screen 
		SDL_RenderPresent(ren);
	}
	/* Creating the surface. */




	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	system("PAUSE");
	return 0;
}
