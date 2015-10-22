#pragma once
#include "MoveDirection.cpp"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class GameObject
{
protected:
	MoveDirection moveDirection = MoveDirection::NONE;
	SDL_Texture* texture = nullptr;
	int width = 0, height = 0;
	SDL_Rect sourceRect = { 0,0,0,0 }, destRect= { 0,0,0,0 };

	float posY = 0.0f;
	float posX = 0.0f;

public:
	GameObject() {}//Default constructer
	virtual ~GameObject() {}

	float getPosY() { return posY; }
	float getPosX() { return posX; }
	
	void SetImage(const char* path, SDL_Renderer& ren) { 
		SDL_Surface * image = IMG_Load(path);
		this->texture = SDL_CreateTextureFromSurface(&ren, image);
		std::cout << "Image Loaded";
	}
	void SetSize(int w, int h) { this->width = w; this->height = h; sourceRect.w = w; sourceRect.h = h; }
	void SetPosition(float x, float y) { destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height }; posX = x; posY = y; }

	void SetSourceRect(SDL_Rect r) { sourceRect = r; }
	void SetDestinationRect(SDL_Rect r) { destRect = r; }

	SDL_Rect const GetSourceRect() { return this->sourceRect; }
	SDL_Rect const GetDestinationRect() { return this->destRect; }
	int const GetHeight() { return this->height; }
	int const GetWidth() { return this->width; }
	SDL_Texture* const GetTexture() { return this->texture; }
	MoveDirection const GetMoveDir() { return this->moveDirection; }
};