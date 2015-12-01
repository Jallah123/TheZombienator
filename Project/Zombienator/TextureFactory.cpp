#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}

SDL_Texture* TextureFactory::GenerateTextureFromTextMenu(std::string text, SDL_Color color)
{

	static TTF_Font* font;
	if (font == nullptr) {
		font = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", 64);
	}
	if (font == nullptr) {
		cout << "Error opening font" << endl;
		return nullptr;
	}

}

SDL_Texture* TextureFactory::GenerateTextureFromTextHud(std::string text, SDL_Color color)
{
	static TTF_Font* font;
	if (font == nullptr) {
		font = TTF_OpenFont("assets/fonts/Roboto-Medium.ttf", 128);
	}
	if (font == nullptr) {
		cout << "Error opening font" << endl;
		return nullptr;
	}

	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);

	SDL_Texture* texture = GenerateTextureFromSurface(textSurface);

	return texture;
}

SDL_Texture* TextureFactory::GenerateTextureFromImgUrl(std::string url)
{
	SDL_Surface* imgSurface = IMG_Load(url.c_str());
	if (imgSurface == NULL)
	{
		cout << "Error loading file" << endl;
		cout << url << endl;
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
 
 std::pair<SDL_Texture*, SDL_Rect> TextureFactory::GenerateText(std::string text, int fontSize, int xPos, int yPos, bool cartoonFont, SDL_Color color) {
	
	std::pair<SDL_Texture*, SDL_Rect> returnObject = {};

	static TTF_Font* font;
	if (font == nullptr) {
		
		if (cartoonFont) {
			font = TTF_OpenFont("assets/fonts/Block-Cartoon.ttf", fontSize);
		}
		else {
			font = TTF_OpenFont("assets/fonts/Roboto-Medium.ttf", fontSize);
		}

	}
	if (font == nullptr) {
		cout << "Error opening font" << endl;
		return returnObject;
	}

	SDL_Surface * surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surface)
	{
		SDL_Rect messageRectange = { xPos - (surface->w / 2), yPos - (surface->h / 2), surface->w, surface->h };
		returnObject = std::make_pair(GenerateTextureFromSurface(surface), messageRectange);
		return returnObject;
	}
}



SDL_Texture* TextureFactory::FindTexture(std::string url)
{
	return textures.at(url);
}

TextureFactory::~TextureFactory()
{
}
