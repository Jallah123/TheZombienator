#pragma once
#include "Map.h"
#include "AbstractScreen.h"
#include "MapParser.h"
#include <memory>

class GameScreen : public AbstractScreen
{
public:
	GameScreen(SDL_Renderer* _ren, string path);
	void Draw(SDL_Renderer& ren);
	~GameScreen() {};
private:
	unique_ptr<Map> map{ nullptr };
	SDL_Renderer* ren;
	Mix_Chunk *sound;
	void DrawRect(int x, int y, SDL_Rect* clip);
	void DrawCollisionObject(int x, int y, int width, int height);
	void loadSounds();
	void playSound();
	void stopSound();
protected:

};