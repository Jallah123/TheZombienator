#include "HudVisitor.h"
#include <SDL_rect.h>
#include <string>
#include "PlayableCharacter.h"
#include "Weapon.h"
#include "TextureFactory.h"
#include "SpawnController.h"
#include <vector>
#include <map>

using std::string;

HudVisitor::HudVisitor(SDL_Renderer* _renderer, SDL_Rect _bounds) : renderer{ _renderer }
{
	bounds = _bounds;
	bloodHud = TextureFactory::CreateTexture("assets/images/hud/hud_blood.png");
	weaponImagePair.first = TextureFactory::CreateTexture("assets/images/hud/hud_guns.png");
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


void HudVisitor::DrawBase(int players)
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

void HudVisitor::Visit(std::vector<PlayableCharacter*> characters)
{
	if (prevValues.empty())
	{
		for (PlayableCharacter* character : characters)
		{
			prevValues.insert_or_assign(character, std::map<std::string, std::string>{});
		}
	}
	for (int i = 0; i < characters.size();i++)
	{
		bloodRect.x = (i* bounds.w);
		bloodRect.y = bounds.h - bloodRect.h - 60;
		if (i > 0)
		{
			bloodRect.x -= bloodRect.w;
		}
		Weapon* weapon = characters.at(i)->GetWeapon();
		const string wName = weapon->GetName();

		//==== Make Ammo Texture
		int wRounds = weapon->GetRounds();
	//	if (to_string(wRounds) != PrevMapValue(characters.at(i), "wRounds") || wName != PrevMapValue(characters.at(i), "wName"))
	//	{
			if (wRounds != INT_MAX)
			{
				const string m_sRounds = std::to_string(wRounds);
				string m_sAmmo = "";
				for (size_t i = 0; i < (ammoFixedSize - m_sRounds.size()); i++)
				{
					m_sAmmo += "0";
				}
				m_sAmmo += m_sRounds;
				ammoTextPair = TextureFactory::CreateText(m_sAmmo, SDL_Point{ bloodRect.x + bloodRect.w - 45, bloodRect.y + horizontalPadding });
				prevValues.at(characters.at(i)).insert_or_assign("wRounds", m_sRounds);
			}
			else
			{
				//Render infinite sign
				ammoTextPair.first = infiniteSign;
				ammoTextPair.second = SDL_Rect{ bloodRect.x + bloodRect.w - 32, bloodRect.y + verticalPadding, 24, 13 };
			}
	//	}

		// === Make Weapon Text Texture
		const int weaponsSize = characters.at(i)->AmountOfWeapons();
		const int currentWeapIndex = characters.at(i)->CurrentWeaponIndex() + 1;

	//	if (wName != PrevMapValue(characters.at(i), "wName"))
	//	{
			const string weaponDetails = weapon->GetName() + " " + std::to_string(currentWeapIndex) + "/" + std::to_string(weaponsSize);
			weaponTextPair = TextureFactory::CreateText(weaponDetails, SDL_Point{ bloodRect.x + horizontalPadding , bloodRect.y });
			weaponTextPair.second.y -= weaponTextPair.second.h;

			//Set Weapon image rectangle 
			weaponImageSrcRect = weapon->GetHudSourceRect();
			weaponImagePair.second = SDL_Rect{
				bloodRect.x + bloodRect.w - horizontalPadding - 110,
				bloodRect.y - horizontalPadding - 40,
				110,
				40
			};

			prevValues.at(characters.at(i)).insert_or_assign("wName", weapon->GetName());
	//	}

		if (weaponTextPair.first != nullptr)
			SDL_RenderCopy(renderer, weaponTextPair.first, 0, &weaponTextPair.second);

		if (ammoTextPair.first != nullptr)
			SDL_RenderCopy(renderer, ammoTextPair.first, 0, &ammoTextPair.second);

		if (weaponImagePair.first != nullptr)
			SDL_RenderCopy(renderer, weaponImagePair.first, &weaponImageSrcRect, &weaponImagePair.second);

		SDL_DestroyTexture(weaponTextPair.first);
		if (ammoTextPair.first != infiniteSign)
		{
			SDL_DestroyTexture(ammoTextPair.first);
		}
	}
}

void HudVisitor::Visit(SpawnController & spawnController)
{
	if (spawnController.WaveCompleted())
	{
		int seconds = spawnController.GetTimeTillNextWave() / 100;
		string m_sCountDown = to_string(seconds);
		if (m_sCountDown != countdown)
		{
			int max = 5;
			int fontSize = 30 * (max - seconds);
			if (seconds == 0) m_sCountDown = "GO";

			SDL_DestroyTexture(countDownTextPair.first);
			countDownTextPair = TextureFactory::CreateText(m_sCountDown, SDL_Point{ bounds.w / 2, 40 }, SDL_Color{ 255,255,255 }, FontEnum::OCR, fontSize);
			countDownTextPair.second.x -= countDownTextPair.second.w / 2;
			countdown = m_sCountDown;
		}
		//Draw the Count down
		if (countDownTextPair.first != nullptr)
			SDL_RenderCopy(renderer, countDownTextPair.first, 0, &countDownTextPair.second);
	}

	// === Render current wave text
	string curWave = std::to_string(spawnController.CurrentWave());

	string waveText = "Wave " + curWave + "/" + std::to_string(spawnController.Waves());
	waveTextPair = TextureFactory::CreateText(waveText, SDL_Point{ bloodRect.x + horizontalPadding, bloodRect.y + verticalPadding });

	if (waveTextPair.first != nullptr)
		SDL_RenderCopy(renderer, waveTextPair.first, 0, &waveTextPair.second);

	SDL_DestroyTexture(waveTextPair.first);
}

std::string const HudVisitor::PrevMapValue(PlayableCharacter* character, std::string index)
{
	if (prevValues.at(character).count(index) == 1)//found
		return prevValues.at(character).at(index);
	return "";
}
