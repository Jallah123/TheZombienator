#pragma once
#include "AbstractUIComponent.h"
#include <string>

class Image :
	public AbstractUIComponent
{
public:
	Image(SDL_Renderer& ren, std::string img_url);
	~Image();
	std::string GetImageUrl() { return img_url; };
	virtual void Draw(SDL_Renderer& ren) override;
	virtual void ClickAction() override;

private:
	SDL_Texture* texture = nullptr;
	std::string img_url = "";
};

