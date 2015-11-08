#include "GameObject.h"
#include "TextureFactory.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetImage(const char * path, SDL_Renderer & ren)
{
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}
