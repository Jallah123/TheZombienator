#include "GameObject.h"
#include "TextureFactory.h"

void GameObject::SetImage(const char * path, SDL_Renderer & ren)
{
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}
