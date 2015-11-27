#include "HudDrawBehaviour.h"
#include "PlayableCharacter.h"
#include "TextureFactory.h"

HudDrawBehaviour::HudDrawBehaviour(GameObject* _gameObject) : DrawBehaviour()
{
	gameObject = _gameObject;
}

void HudDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	SDL_SetRenderDrawBlendMode(&ren, SDL_BLENDMODE_BLEND);

	// Border
	SDL_Rect Border{ 0, 0, 306, 116 };
	SDL_SetRenderDrawColor(&ren, 241, 35, 24, 150);
	SDL_RenderFillRect(&ren, &Border);

	// Orange Background
	SDL_SetRenderDrawColor(&ren, 255, 102, 49, 110);
	SDL_Rect rect{3, 3, 300, 110};
	SDL_RenderFillRect(&ren, &rect);
	
	// Draw pistol
	PlayableCharacter* pc = static_cast<PlayableCharacter*>(gameObject);
	SDL_Texture* weaponTexture = pc->GetWeapon()->GetHudTexture();
	SDL_Rect r{0, 50, 81, 50};
	SDL_RenderCopy(&ren, weaponTexture, 0, &r);

	// Only create texture if weapon actually has a name
	if (pc->GetWeapon()->GetName() != "")
	{
		// Create new texture if weapon changed
		if (pc->GetWeapon()->GetName() != weaponName)
		{
			weaponNameTexture = TextureFactory::GenerateTextureFromTextHud(pc->GetWeapon()->GetName());
			weaponName = pc->GetWeapon()->GetName();
		}
	}

	SDL_Rect weaponTextTexture{ 45, 75, 60, 28 };
	// Draw pistol text
	if (weaponNameTexture != nullptr)
	{
		SDL_RenderCopy(&ren, weaponNameTexture, 0, &weaponTextTexture);
	}
	SDL_Texture* roundsTextTexture = TextureFactory::GenerateTextureFromTextHud("rounds : " + to_string(pc->GetWeapon()->GetRounds()));
	weaponTextTexture.w += 40;
	weaponTextTexture.x += 150;
	weaponTextTexture.y += 15;
	SDL_RenderCopy(&ren, roundsTextTexture, 0, &weaponTextTexture);
	SDL_DestroyTexture(roundsTextTexture);

}

HudDrawBehaviour::~HudDrawBehaviour()
{
}
