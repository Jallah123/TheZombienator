#pragma once
#include "Direction.cpp"
#include "SDL.h"
#include <iostream>
#include "Map.h"

class GameObject
{
protected:
	Direction moveDir = Direction::NONE;
	Direction lookDir = Direction::SOUTH;
	SDL_Texture* texture = nullptr;
	int width = 0, height = 0;
	SDL_Rect sourceRect = { 0,0,0,0 }, destRect= { 0,0,0,0 };

	float posY = 0.0f;
	float posX = 0.0f;
	
public:
	GameObject();//Default constructer
	virtual ~GameObject();

	float getPosY() { return posY; }
	float getPosX() { return posX; }
	
	void SetImage(const char* path, SDL_Renderer& ren); 
	void SetTexture(SDL_Texture* t) { this->texture = t; }
	void SetSize(int w, int h) { this->width = w; this->height = h; sourceRect.w = w; sourceRect.h = h; }
	void SetPosition(float x, float y) { destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height }; posX = x; posY = y; }
	void SetMoveDir(Direction d) { if (moveDir != d) moveDir = d; }
	void SetLookDir(Direction d) { if(lookDir != d) lookDir = d; }
	void SetSourceRect(SDL_Rect r) { sourceRect = r; }
	void SetDestinationRect(SDL_Rect r) { destRect = r; }

	SDL_Rect const GetSourceRect() { return this->sourceRect; }
	SDL_Rect* GetDestinationRect() { return &this->destRect; }
	int const GetHeight() { return this->height; }
	int const GetWidth() { return this->width; }
	SDL_Texture* const GetTexture() { return this->texture; }
	Direction const GetMoveDir() { return this->moveDir; }
	Direction const GetLookDir() { return this->lookDir; }
};