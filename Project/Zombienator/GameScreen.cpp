#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(SDL_Renderer* _ren, string path) : AbstractScreen(ren)
{
	 ren = _ren; 
	 MapParser mp{};
	 map = mp.ParseJsonMap(path);
	 map.get()->setSprites(mp.GenerateSprites(path));
	 SDL_Surface* s;
	 s = IMG_Load("assets/maps/TestMap/mountain_landscape_23.png");
	 if (!s) {
		 cout << "Error image load : " << IMG_GetError() << endl;
		 return;
	 }
	 map.get()->setTexture(SDL_CreateTextureFromSurface(ren, s));
	 SDL_FreeSurface(s);
};

void GameScreen::Draw(SDL_Renderer& ren)
{
	vector<SDL_Rect*> sprites = map.get()->getSprites();
	int index = 0;
	for (int x = 0; x < 24; x++)
	{
		for (int y = 0; y < 32; y++)
		{
			DrawRect(x * 32, y * 32, sprites.at(map->getLayer().getGID(x, y)));
		}
	}
}

void GameScreen::DrawRect(int x, int y, SDL_Rect* clip) { 
	//Set rendering space and render to screen 
	SDL_Rect renderQuad = { y, x, 32, 32 }; 
	//Set clip rendering dimensions 
	if( clip != NULL ) { 
		renderQuad.w = clip->w;
		renderQuad.h = clip->h; 
	}
	//Render to screen 
	SDL_RenderCopy( ren, map.get()->getTexture(), clip, &renderQuad );
}