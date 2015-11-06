#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}


SDL_Texture* TextureFactory::GenerateTexture(std::string url)
{
	SDL_Surface* s = IMG_Load(url.c_str());

	Program& p = Program::shared_program();

	SDL_Renderer* ren = p.GetRenderer();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	// textures.insert(make_pair(url, texture));
	return texture;
}

SDL_Texture* TextureFactory::FindTexture(std::string url)
{
	return textures.at(url);
}

TextureFactory::~TextureFactory()
{
}
