#pragma once
#include "LoadingScreen.h"
#include <SDL_render.h>
#include "AbstractScreen.h"
#include "TextureFactory.h"

class LoadingScreen : public AbstractScreen
{
protected:
	SDL_Texture* BackgroundTexture;
public:
	LoadingScreen(SDL_Renderer* _ren);
	~LoadingScreen();

	void SetBackgroundTexture(SDL_Texture& Texture) { BackgroundTexture = &Texture; }
	SDL_Texture* const GetBackgroundTexture() { return BackgroundTexture; }

	virtual void Update(float dt) override;
	virtual void Draw(SDL_Renderer& ren, float dt) override;
private:
	
};