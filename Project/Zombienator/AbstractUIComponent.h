#pragma once
#include "SDL.h"
class AbstractUIComponent : public SDL_Rect
{
public:
	AbstractUIComponent();
	~AbstractUIComponent();
	void SetDimension(SDL_Rect d) { SetDimensions(d.x, d.y, d.w, d.h); }
	void SetLocation(int xx, int yy) { x = xx; y = yy; }
	void SetDimensions(int xx, int yy, int ww, int hh) { SetLocation(yy, xx); SetSize(ww, hh); }
	void SetSize(int ww, int hh) { w = ww; h = hh; };
	SDL_Rect* const GetDimensions() { return this; }
	void OnClick(SDL_Point MousePosition);
protected:
	
private:
	virtual void ClickAction() = 0;
	virtual void Draw(SDL_Renderer& ren) = 0;
};

