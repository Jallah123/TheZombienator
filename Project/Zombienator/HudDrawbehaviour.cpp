#include "HudDrawbehaviour.h"
#include "PlayableCharacter.h"

HudDrawbehaviour::HudDrawbehaviour()
{
}

void HudDrawbehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	PlayableCharacter* pc = static_cast<PlayableCharacter*>(gameObject);
	SDL_Texture* weaponTexture = pc->GetWeapon()->GetHudTexture();
	SDL_Rect r{0, 10, 75, 75};
	SDL_RenderCopy(&ren, weaponTexture, 0, &r);
}

HudDrawbehaviour::~HudDrawbehaviour()
{
}
