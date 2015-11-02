#pragma once
#include "MoveDirection.cpp"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Map.h"

class GameObject
{
private:
	bool canRemove = false;
protected:
	MoveDirection moveDirection = MoveDirection::SOUTH;
	SDL_Texture* texture = nullptr;
	int width = 0, height = 0;
	SDL_Rect sourceRect = { 0,0,0,0 }, destRect= { 0,0,0,0 };

	float posY = 0.0f;
	float posX = 0.0f;

	// -- Map
	Map* map;

public:
	GameObject() {}//Default constructer
	virtual ~GameObject() {}

	float getPosY() { return posY; }
	float getPosX() { return posX; }
	
	void SetImage(const char* path, SDL_Renderer& ren); 
	void SetTexture(SDL_Texture* t) { this->texture = t; }
	void SetSize(int w, int h) { this->width = w; this->height = h; sourceRect.w = w; sourceRect.h = h; }
	void SetPosition(float x, float y) { destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height }; posX = x; posY = y; }
	void SetMoveDir(MoveDirection d) { moveDirection = d; }
	void SetSourceRect(SDL_Rect r) { sourceRect = r; }
	void SetDestinationRect(SDL_Rect r) { destRect = r; }

	SDL_Rect const GetSourceRect() { return this->sourceRect; }
	SDL_Rect const GetDestinationRect() { return this->destRect; }
	int const GetHeight() { return this->height; }
	int const GetWidth() { return this->width; }
	SDL_Texture* const GetTexture() { return this->texture; }
	MoveDirection const GetMoveDir() { return this->moveDirection; }

	// -- Map
	Map* getMap() { return map; }
	void setMap(Map* m) { map = m; }


	// -- Remove
	bool CanBeRemoved() { return this->canRemove; }
	void CanRemove(bool c) { this->canRemove = c; }
};