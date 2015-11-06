#pragma once
#include "Map.h"
#include "AbstractScreen.h"
#include "MapParser.h"
#include <memory>
#include <SDL_render.h>

class GameScreen : public AbstractScreen
{
public:
	GameScreen(SDL_Renderer* _ren, char* path);
	~GameScreen();

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	void DrawMap(SDL_Renderer& ren);
	
private:
	Map* map = nullptr;
	
	void DrawRect(int x, int y, SDL_Rect* clip, SDL_Renderer* ren);
	void DrawCollisionObject(int x, int y, int width, int height, SDL_Renderer* ren);
};