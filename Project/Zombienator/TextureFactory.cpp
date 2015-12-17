#include "TextureFactory.h"

TextureFactory::TextureFactory()
{
}

std::map<FontEnum, char*> fillMap()
{
	std::map<FontEnum, char*> map;
	map[FontEnum::CARTOON] = "assets/fonts/Block-Cartoon.ttf";
	map[FontEnum::ROBOTO] = "assets/fonts/Roboto-Medium.ttf";
	map[FontEnum::OCR] = "assets/fonts/OCR-A-Ectended.ttf";
	return map;
}

std::map<FontEnum, char*> TextureFactory::FontMap = fillMap();

SDL_Texture* TextureFactory::GenerateTextureFromTextMenu(std::string text, SDL_Color color)
{

	static TTF_Font* font;
	if (font == nullptr) {
		font = TTF_OpenFont(FontMap[FontEnum::CARTOON], 64);
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
		font = TTF_OpenFont(FontMap[FontEnum::ROBOTO], 128);
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
		if(fontEnum == FontEnum::OCR)
			messageRectange = { xPos, yPos, surface->w, surface->h };
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
