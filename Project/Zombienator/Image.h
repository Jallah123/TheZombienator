#pragma once
#include "AbstractUIComponent.h"

class Image :
	public AbstractUIComponent
{
public:
	Image(SDL_Renderer& ren, char* img_url);
	~Image();

	virtual void Draw(SDL_Renderer& ren) override;
	virtual void ClickAction() override;
	
private:
	SDL_Texture* texture;
};

