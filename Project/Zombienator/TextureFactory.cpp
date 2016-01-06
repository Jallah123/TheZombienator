#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}

TextureFactory::~TextureFactory()
{
}


std::map<FontEnum, char*> fillMap()
{
	std::map<FontEnum, char*> map = {
		{ FontEnum::CARTOON, "assets/fonts/Block-Cartoon.ttf" },
		{ FontEnum::ROBOTO, "assets/fonts/Roboto-Medium.ttf" },
		{ FontEnum::OCR, "assets/fonts/OCR-A-Ectended.ttf" }
	};
	return map;
}

std::map<FontEnum, char*> TextureFactory::FontMap = fillMap();

SDL_Texture * TextureFactory::CreateTexture(string url)
{
	if (url.empty()) {
		cerr << "Empty image url \n";
		return nullptr;
	}
	SDL_Surface* surface = IMG_Load(url.c_str());
	if (surface == NULL)
	{
		cerr << "Error loading file \n";
		cerr << url << endl;
		return nullptr;
	}
	SDL_Texture* texture = GenerateTextureFromSurface(surface);
	
	return texture;
}

std::pair<SDL_Texture*, SDL_Rect> TextureFactory::CreateText(string text, SDL_Color color, FontEnum fontType, int fontSize)
{
	std::pair<SDL_Texture*, SDL_Rect> pair = {};
	TTF_Font* font = TTF_OpenFont(FontMap[fontType], fontSize);

	if (font == nullptr) {
		cerr << "Error opening font \n";
		return pair;
	}
	SDL_Surface * surface = TTF_RenderText_Blended(font, text.c_str(), color);
	if (surface == nullptr) {
		cerr << "Error creating font surface \n";
		return pair;
	}
	SDL_Texture* texture = GenerateTextureFromSurface(surface);
	TTF_CloseFont(font);
	return pair = { texture, SDL_Rect{ 0, 0, surface->w, surface->h } };
}

std::pair<SDL_Texture*, SDL_Rect> TextureFactory::CreateText(string text, SDL_Point position, SDL_Color color, FontEnum font, int fontSize)
{
	std::pair<SDL_Texture*, SDL_Rect> pair = CreateText(text, color, font, fontSize);
	pair.second.x = position.x;
	pair.second.y = position.y;

	return pair;
}


SDL_Texture* TextureFactory::GenerateTextureFromSurface(SDL_Surface* surface)
{
	Program* p = Program::getInstance();

	SDL_Renderer* ren = p->GetRenderer();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	if (texture == NULL) 
	{
		cerr << "Error creating texture from surface \n";
	}
	SDL_FreeSurface(surface);
	return texture;
}

std::pair<SDL_Texture*, SDL_Rect> TextureFactory::GenerateText(std::string text, int fontSize, int xPos, int yPos, FontEnum fontEnum, SDL_Color color, int multipleLinesSize)
{	
	std::pair<SDL_Texture*, SDL_Rect> returnObject = {};
	static FontEnum currentFont;
	static int _fontSize;
	static TTF_Font* font;

	if (font == nullptr || fontEnum != currentFont || _fontSize != fontSize) {
		if (font != nullptr)
		{
			TTF_CloseFont(font);
		}
		font = TTF_OpenFont(FontMap[fontEnum], fontSize);
	}

	if (font == nullptr) {
		cout << "Error opening font" << endl;
		return returnObject;
	}

	SDL_Surface * surface = nullptr;
	if (multipleLinesSize > 0) {
		surface = TTF_RenderText_Blended_Wrapped(font, text.c_str(), color, multipleLinesSize);
	}
	else {
		surface = TTF_RenderText_Blended(font, text.c_str(), color);
	}
	if (surface)
	{
		SDL_Rect messageRectange = { xPos - (surface->w / 2), yPos - (surface->h / 2), surface->w, surface->h };
		if (fontEnum == FontEnum::OCR)
			messageRectange = { xPos, yPos, surface->w, surface->h };
		returnObject = std::make_pair(GenerateTextureFromSurface(surface), messageRectange);
		return returnObject;
	}
}
