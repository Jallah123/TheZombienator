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
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void GameObject::SetPosition(float x, float y)
{
	destRect = { (int)(x + 0.5f), (int)(y + 0.5f), width, height }; 
	posX = x; 
	posY = y;
	collRect.x = destRect.x;
	collRect.y = destRect.y;
}
