#include "TileSet.h"
#include "TextureFactory.h"

TileSet::TileSet()
{
	
}


TileSet::TileSet(string image, int gid, int imgW, int imgH, int tileW, int tileH)
	: image(image), firstgid(gid), imageWidth(imgW), imageHeight(imgH), tileWidth(tileW), tileHeight(tileH)
{
	rect = new SDL_Rect{ 0,0,ImageWidth(),ImageHeight() };
	for (int y = 0; y < ImageWidth(); y += TileWidth())
	{
		for (int x = 0; x < ImageHeight(); x += TileHeight())
		{
			tiles.push_back(new SDL_Rect{ x, y, TileWidth(), TileHeight() });
		}
	}
}


TileSet::~TileSet()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
	delete rect;
}

void TileSet::Load(SDL_Renderer& ren)
{
	string path = assetsPath + image;
	texture = TextureFactory::GenerateTextureFromImgUrl(path);
}
