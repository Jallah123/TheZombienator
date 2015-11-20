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
