#include "HudVisitor.h"
#include "Character.h"
#include "Weapon.h"
#include "TextureFactory.h"

HudVisitor::HudVisitor(SDL_Renderer* _renderer)
{
	renderer = _renderer;
}

void HudVisitor::DrawBase()
{
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	// Border
	SDL_Rect Border{ 0, 0, 306, 116 };
	SDL_SetRenderDrawColor(renderer, 241, 35, 24, 150);
	SDL_RenderFillRect(renderer, &Border);

	// Orange Background
	SDL_SetRenderDrawColor(renderer, 255, 102, 49, 110);
	SDL_Rect rect{ 3, 3, 300, 110 };
	SDL_RenderFillRect(renderer, &rect);
}

void HudVisitor::Visit(Character* character)
{

}

void HudVisitor::Visit(Weapon* weapon)
{
	SDL_Rect r{ 0, 50, 81, 50 };
	SDL_RenderCopy(renderer, weapon->GetHudTexture(), 0, &r);

	if (weapon->GetName() != "")
	{
		// Create new texture if weapon changed
		if (weapon->GetName() != weaponName)
		{
			weaponNameTexture = TextureFactory::GenerateTextureFromTextHud(weapon->GetName());
			weaponName = weapon->GetName();
		}
	}

	SDL_Rect weaponTextTexture{ 55, 75, 60, 28 };
	// Draw pistol text
	if (weaponNameTexture != nullptr)
	{
		SDL_RenderCopy(renderer, weaponNameTexture, 0, &weaponTextTexture);
	}

	// Draw rounds
	int rounds = weapon->GetRounds();
	std::string s_rounds = rounds == INT_MAX ? "INFINITE" : to_string(rounds);
	SDL_Texture* roundsTextTexture = TextureFactory::GenerateTextureFromTextHud("rounds : " + s_rounds);
	weaponTextTexture.w += 30;
	weaponTextTexture.x += 150;
	weaponTextTexture.y += 15;
	SDL_RenderCopy(renderer, roundsTextTexture, 0, &weaponTextTexture);
	SDL_DestroyTexture(roundsTextTexture);
}

HudVisitor::~HudVisitor()
{
}
