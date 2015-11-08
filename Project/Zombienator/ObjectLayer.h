#pragma once
#include "Layer.h"
#include <vector>

using std::vector;
class Map;
class ObjectLayer :
	public Layer
{
	vector<SDL_Rect*> rects{};
	
public:
	ObjectLayer();
	~ObjectLayer();

	virtual void Draw(SDL_Renderer& ren) override;

	void AddRect(SDL_Rect* r) { rects.push_back(r); }
	vector<SDL_Rect*> GetRects() { return this->rects; }

	bool HasCollision(const SDL_Rect* src);
};
