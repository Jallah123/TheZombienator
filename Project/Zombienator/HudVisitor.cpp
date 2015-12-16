#include "HudVisitor.h"
#include <SDL_rect.h>
#include <string>
#include "PlayableCharacter.h"
#include "Weapon.h"
#include "TextureFactory.h"
#include "SpawnController.h"

using std::string;

HudVisitor::HudVisitor(SDL_Renderer* _renderer, SDL_Rect _bounds) : renderer{ _renderer }
{
	bounds = _bounds;
	bloodHud = TextureFactory::CreateTexture("assets/images/hud/hud_blood.png");
	weaponSpritesheet = TextureFactory::CreateTexture("assets/images/hud/hud_guns.png");
	infiniteSign = TextureFactory::CreateTexture("assets/images/hud/infinite_sign.png");
}


HudVisitor::~HudVisitor()
{
	/*SDL_DestroyTexture(weaponSpritesheet);
	weaponSpritesheet = NULL;
	SDL_DestroyTexture(weaponNameTexture);
	weaponNameTexture = NULL;
	SDL_DestroyTexture(ammoTextTexture);
	ammoTextTexture = NULL;
	SDL_DestroyTexture(bloodHud);
	bloodHud = NULL;
	SDL_DestroyTexture(infiniteSign);
	infiniteSign = NULL;*/
}


void HudVisitor::DrawBase()
{

	for (size_t i = 0; i < players; i++)
	{
		bloodRect.x = (i* bounds.w);
		bloodRect.y = bounds.h - bloodRect.h - 60;
		if (i > 0)
		{
			bloodRect.x -= bloodRect.w;
		}
		SDL_RenderCopy(renderer, bloodHud, 0, &bloodRect);
	}

}

void HudVisitor::Visit(PlayableCharacter& character)
{
	Weapon* weapon = character.GetWeapon();
	const string wName = weapon->GetName();

	//==== Make Ammo Texture
	int wRounds = weapon->GetRounds();
	if (to_string(wRounds) != PrevMapValue("wRounds") || wName != PrevMapValue("wName")) {
		if (wRounds != INT_MAX) {
			const string m_sRounds = std::to_string(wRounds);
			string m_sAmmo = "";
			for (size_t i = 0; i < (ammoFixedSize - m_sRounds.size()); i++)
			{
				m_sAmmo += "0";
			}
			m_sAmmo += m_sRounds;
			ammoTextPair = TextureFactory::CreateText(m_sAmmo, SDL_Point{ bloodRect.x + bloodRect.w - 35, bloodRect.y + horizontalPadding });
			prevValues.insert_or_assign("wRounds", m_sRounds);
		}
		else {
			//Render infinite sign
			ammoTextPair.first = infiniteSign;
			ammoTextPair.second = SDL_Rect{ bloodRect.x + bloodRect.w - 32, bloodRect.y + verticalPadding, 24, 13 };
		}
	}

	// === Make Weapon Text Texture
	const int weaponsSize = character.AmountOfWeapons();
	const int currentWeapIndex = character.CurrentWeaponIndex() + 1;
	
	if (wName != PrevMapValue("wName"))
	{
		const string weaponDetails = weapon->GetName() + " " + std::to_string(currentWeapIndex) + "/" + std::to_string(weaponsSize);
		weaponTextPair = TextureFactory::CreateText(weaponDetails, SDL_Point{ bloodRect.x + horizontalPadding , bloodRect.y });
		weaponTextPair.second.y -= weaponTextPair.second.h;

		prevValues.insert_or_assign("wName", weapon->GetName());
	}

	if (weaponTextPair.first != nullptr)
		SDL_RenderCopy(renderer, weaponTextPair.first, 0, &weaponTextPair.second);

	if (ammoTextPair.first != nullptr)
		SDL_RenderCopy(renderer, ammoTextPair.first, 0, &ammoTextPair.second);

}
void HudVisitor::Visit(SpawnController & spawnController)
{
	int zombiesOnScreen = spawnController.GetAmountSpawned();
	int zombiesLeft = spawnController.GetAmountToSpawn() - zombiesOnScreen;
	string s = "Zombies left to spawn : " + std::to_string(zombiesLeft);
	if (zombiesLeft == 0) {
		s = "Kill all zombies";
		if (spawnController.AllWavesCompleted()) {
			s = "Next map in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}
		else if (spawnController.WaveCompleted()) {
			s = "Next wave in: " + std::to_string(spawnController.GetTimeTillNextWave() / 100);
		}

	}


	auto pair = TextureFactory::CreateText(s);

	SDL_RenderCopy(renderer, pair.first, 0, &pair.second);


	// === Render current wave text
	string curWave = std::to_string(spawnController.CurrentWave());

	if (curWave != PrevMapValue("curWave"))
	{
		string waveText = "Wave " + curWave + "/" + std::to_string(spawnController.Waves());
		waveTextPair = TextureFactory::CreateText(waveText, SDL_Point{ bloodRect.x + horizontalPadding, bloodRect.y + verticalPadding });
	}
	
	if (waveTextPair.first != nullptr)
		SDL_RenderCopy(renderer, waveTextPair.first, 0, &waveTextPair.second);
}
std::string const HudVisitor::PrevMapValue(std::string index)
{
	if (prevValues.count(index) == 1)//found
		return prevValues.at(index);
	return "";
}
/*
void HudVisitor::Visit(Weapon* weapon)
{
	SDL_Rect r{ 0, bloodRect.y - 200, 81, 50 };
	//SDL_RenderCopy(renderer, weapon->GetHudTexture(), 0, &r);
	//SDL_RenderCopy(renderer, weaponSpritesheet, 0, &r);
	std::string weaponDetails = weapon->GetName() + "/"
		if (weapon->GetName() != "")
		{
			// Create new texture if weapon changed
			if (weapon->GetName() != weaponName)
			{
				if (weaponNameTexture != nullptr)
				{
					SDL_DestroyTexture(weaponNameTexture);
				}
				weaponNameTexture = TextureFactory::GenerateTextureFromTextHud(weapon->GetName());
				weaponName = weapon->GetName();
			}
		}

	SDL_Rect weaponTextTexture{ 55, bounds.h - 40, 60, 28 };
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
*/