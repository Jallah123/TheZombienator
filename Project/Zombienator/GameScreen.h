#pragma once
#include "Map.h"
#include "AbstractScreen.h"
#include "MapParser.h"
#include <memory>

class GameScreen : public AbstractScreen
{
public:
	GameScreen(SDL_Renderer* _ren, string path);

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
	~GameScreen();
private:
	unique_ptr<Map> map{ nullptr };
	Mix_Chunk *sound;
	void DrawRect(int x, int y, SDL_Rect* clip, SDL_Renderer* ren);
	void DrawCollisionObject(int x, int y, int width, int height, SDL_Renderer* ren);
	
};