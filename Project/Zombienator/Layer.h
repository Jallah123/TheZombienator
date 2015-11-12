#pragma once
#include <string>
#include <vector>
#include <SDL_rect.h>
#include <SDL_render.h>
using std::string;
using std::vector;

class Map;

class Layer
{
protected:
	size_t width = 0;
	size_t height = 0;
	string name = "";
	string type = "";
	
	Map* map;
public:
	Layer();
	Layer(Map* map);
	virtual ~Layer();

	virtual void Draw(SDL_Renderer& ren) = 0;

	void Width(size_t w) { this->width = w; }
	size_t Width() { return this->width; }

	void Height(size_t h) { this->height = h; }
	size_t Height() { return this->height; }

	void Name(string n) { this->name = n; }
	string Name() { return this->name; }

	void Type(string t) { this->type = t; }
	string Type() { return this->type; }
	
	void DrawRect(SDL_Rect* srcRect, SDL_Texture* texture, SDL_Rect* destRect, SDL_Renderer& ren);
	void DrawRect(SDL_Rect* rect, SDL_Renderer& ren);
};

