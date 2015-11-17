#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}

SDL_Texture* TextureFactory::GenerateTextureFromText(std::string text, SDL_Color color)
{
	static TTF_Font* font = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 1024);

	if (font == nullptr) {
		cout << "Error opening font" << endl;
		return nullptr;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

	SDL_Texture* texture = GenerateTextureFromSurface(textSurface);

	return texture;
}

SDL_Texture* TextureFactory::GenerateTextureFromImgUrl(std::string url)
{
	SDL_Surface* imgSurface = IMG_Load(url.c_str());
	if (imgSurface == NULL)
	{
		// log something
	}
	SDL_Texture* texture = GenerateTextureFromSurface(imgSurface);
	if (texture == NULL)
	{
		// log something
	}
	// textures.insert(make_pair(url, texture));
	return texture;
}

SDL_Texture* TextureFactory::GenerateTextureFromSurface(SDL_Surface* surface)
{
	Program* p = Program::getInstance();

	SDL_Renderer* ren = p->GetRenderer();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture* TextureFactory::FindTexture(std::string url)
{
	return textures.at(url);
}

TextureFactory::~TextureFactory()
{
}
