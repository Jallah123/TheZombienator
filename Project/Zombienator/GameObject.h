#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "MoveDirection.cpp"
#include "SDL.h"
#include "SDL_image.h"

#pragma once
class AnimateContainer;

class GameObject
{
protected:
	MoveDirection moveDirection;
	SDL_Texture* texture = nullptr;
	int width, height;
	SDL_Rect sourceRect, destRect;
	//Containers
	AnimateContainer* animateContainer = nullptr;
	/*DrawContainer drawContainer;
	InputContainer inputContainer;
	CollideContainer collideContainer;*/

	//Behaviours

public:
	GameObject();//Default constructer
	GameObject(AnimateContainer& animC);
	~GameObject();
	
	void SetImage(const char* path, SDL_Renderer& ren) { 
		SDL_Surface * image = IMG_Load(path);
		this->texture = SDL_CreateTextureFromSurface(&ren, image);
	}
	void SetSize(int w, int h) { this->width = w; this->height = h; }
	void SetPosition(int x, int y) { destRect = { x, y, width, height }; }

	int const GetHeight() { return this->height; }
	int const GetWidth() { return this->width; }
	SDL_Texture* const GetTexture() { return this->texture; }
	MoveDirection const GetMoveDir() { return this->moveDirection; }

};

#endif