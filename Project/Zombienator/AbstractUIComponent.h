#pragma once
#include <SDL_render.h>

class AbstractUIComponent
{
public:
	AbstractUIComponent();
	AbstractUIComponent(SDL_Renderer& ren);
	virtual ~AbstractUIComponent();

	void SetSize(int w, int h);
	void SetDestLocation(int x, int y);
	void SetSourceLocation(int x, int y);
	
	SDL_Rect const GetDestRect() { return destRect; }
	SDL_Rect const GetSrcRect() { return srcRect; }

	bool OnClick(SDL_Point mousePosition);
	virtual void Draw(SDL_Renderer& ren) = 0;
	
protected:
	SDL_Renderer* renderer;
	SDL_Texture* message = nullptr;
	SDL_Texture* image = nullptr;
	SDL_Rect srcRect{};
	SDL_Rect destRect{};

	virtual void ClickAction() = 0;
};

