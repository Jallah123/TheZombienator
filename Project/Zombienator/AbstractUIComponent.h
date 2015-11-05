#pragma once
#include "SDL.h"
#include "SDL_ttf.h"

class AbstractUIComponent : public SDL_Rect
{
public:
	AbstractUIComponent(SDL_Renderer& ren);
	void SetDimension(SDL_Rect d) { SetDimensions(d.x, d.y, d.w, d.h); }
	void SetLocation(int xx, int yy) { x = xx; y = yy; }
	void SetDimensions(int xx, int yy, int ww, int hh) { SetLocation(xx, yy); SetSize(ww, hh); }
	void SetSize(int ww, int hh) { w = ww; h = hh; };
	SDL_Rect* const GetDimensions() { return this; }
	void OnClick(SDL_Point MousePosition);
	virtual void Draw(SDL_Renderer& ren) = 0;
	virtual ~AbstractUIComponent();
protected:
	SDL_Renderer* instance;
	SDL_Texture* Message;
	SDL_Texture* Image;
private:
	virtual void ClickAction() = 0;
};

