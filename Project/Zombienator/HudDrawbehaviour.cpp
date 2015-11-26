#include "HudDrawBehaviour.h"
#include "PlayableCharacter.h"
#include <iostream>

HudDrawBehaviour::HudDrawBehaviour(GameObject* _gameObject) : DrawBehaviour()
{
	gameObject = _gameObject;
}

void HudDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	SDL_SetRenderDrawBlendMode(&ren, SDL_BLENDMODE_BLEND);

	SDL_Rect Border{ 0, 0, 306, 116 };
	SDL_SetRenderDrawColor(&ren, 241, 35, 24, 150);
	SDL_RenderFillRect(&ren, &Border);

	SDL_SetRenderDrawColor(&ren, 255, 102, 49, 110);
	SDL_Rect rect{3, 3, 300, 110};
	SDL_RenderFillRect(&ren, &rect);

	PlayableCharacter* pc = static_cast<PlayableCharacter*>(gameObject);
	SDL_Texture* weaponTexture = pc->GetWeapon()->GetHudTexture();
	SDL_Rect r{0, 50, 81, 50};
	// SDL_SetRenderTarget()
	SDL_SetTextureBlendMode(weaponTexture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(&ren, weaponTexture, 0, &r);
}

HudDrawBehaviour::~HudDrawBehaviour()
{
}
