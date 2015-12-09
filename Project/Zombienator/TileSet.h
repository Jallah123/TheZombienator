#pragma once
#include <string>
#include <vector>
#include <SDL_render.h>
using std::string;
using std::vector;

class TileSet
{
	const string assetsPath = "assets/maps/";
	string image = "";
	int firstgid = 0;
	
	int imageWidth = 0;
	int imageHeight = 0;

	int tileWidth = 0;
	int tileHeight = 0;

	SDL_Texture* texture = nullptr;
	SDL_Rect* rect = nullptr;
	vector<SDL_Rect*> tiles{};

public:
	TileSet();
	TileSet(string image, int gid, int imgW, int imgH, int tileW, int tileH);
	~TileSet();

	void Load(SDL_Renderer& ren);

	int ImageWidth() { return static_cast<int>(imageWidth); }
	int ImageHeight() { return static_cast<int>(imageHeight); }
	void setImageWidth(int _imageWidth) { imageWidth = _imageWidth; };
	void setImageHeight(int _imageHeight) { imageHeight = _imageHeight; };

	int TileWidth() { return static_cast<int>(tileWidth); }
	int TileHeight() { return static_cast<int>(tileHeight); }
	void setTileWidth(int _tileWidth) { tileWidth = _tileWidth; };
	void setTileHeight(int _tileHeight) { tileHeight = _tileHeight; };

	int GID() { return static_cast<int>(firstgid); }
	SDL_Texture* Texture() { return this->texture; }
	
	SDL_Rect* Rect() { return rect; }
	vector<SDL_Rect*> Tiles() { return this->tiles; }
	SDL_Rect* GetTile(int i) { return tiles[i]; }
};

