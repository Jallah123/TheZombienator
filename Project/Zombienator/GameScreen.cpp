#include "GameScreen.h"
#include <iostream>

GameScreen::GameScreen(SDL_Renderer* _ren, string path) : AbstractScreen(ren)
{
	 ren = _ren; 
	 MapParser mp{};
	 map = mp.ParseJsonMap(path);
	 map.get()->setSprites(mp.GenerateSprites(path));
	 SDL_Surface* s;
	 s = IMG_Load(map->getImagePath().c_str());
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
	vector<MapLayer> layers = map.get()->getLayers();
	vector<CollisionLayer> collisionLayers = map.get()->getCollisionLayers();
	
	for (int i = layers.size()-1; i >= 0; i--)
	{
		for (int x = 0; x < 24; x++)
		{
			for (int y = 0; y < 32; y++)
			{
				DrawRect(x * 32, y * 32, sprites.at(layers.at(i).getGID(x, y)));
			}
		}
	}

	for (int j = collisionLayers.size() - 1; j >= 0; j--)
	{
		
		vector<CollisionObject> collisionObjects = collisionLayers[j].getCollisionObjects();

		for (int k = collisionObjects.size() - 1; k >= 0; k--)
		{
			/* For debugging purposes only */
			DrawCollisionObject(collisionObjects[k].getY(), collisionObjects[k].getX(), collisionObjects[k].getHeight(), collisionObjects[k].getWidth());
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

/* For debugging purposes only */
void GameScreen::DrawCollisionObject(int x, int y, int height, int width) {
	//Set rendering space and render to screen 
	SDL_Rect rectangle = { y, x, height, width };
	//Render to screen
	SDL_RenderDrawRect(ren, &rectangle );
}