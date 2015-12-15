#include "GameObject.h"
#include "TextureFactory.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetImage(std::string path, SDL_Renderer & ren)
{
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void GameObject::SetSize(int w, int h)
{
   	this->width = w; 
	this->height = h; 
	sourceRect.w = w; 
	sourceRect.h = h; 
	collRect.w = w; 
	collRect.h = h / 2;
}

void GameObject::SetPosition(float x, float y)
{
	destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height }; 
	posX = x; 
	posY = y;
	collRect.x = destRect.x;
	collRect.y = destRect.y + collRect.h;
}
