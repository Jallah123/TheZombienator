#include <iostream>
#include "Program.h"

using namespace std;

SDL_Window *win = nullptr;
SDL_Renderer *ren = nullptr;
SDL_Event e;

int main(int argc, char* args[])
{
	Program::shared_program();
	return 0;
}
