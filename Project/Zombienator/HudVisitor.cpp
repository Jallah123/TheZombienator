#include "HudVisitor.h"
#include <SDL_rect.h>
#include <vector>
#include <map>
#include <string>
#include "PlayableCharacter.h"
#include "Weapon.h"
#include "TextureFactory.h"
#include "SpawnController.h"
#include "GameTypeEnum.cpp"

using std::string;

HudVisitor::HudVisitor(SDL_Renderer* _renderer, SDL_Rect _bounds, size_t players) : renderer{ _renderer }, players{ players }
{
	bounds = _bounds;
	bloodHud = TextureFactory::CreateTexture("assets/images/hud/hud_blood.png");
	weaponImagePair.first = TextureFactory::CreateTexture("assets/images/hud/hud_guns.png");
	infiniteSign = TextureFactory::CreateTexture("assets/images/hud/infinite_sign.png");
	
	ammoTextPairs = vector<pair<SDL_Texture*, SDL_Rect>>(players);
	weaponTextPairs = vector<pair<SDL_Texture*, SDL_Rect>>(players);

	for (size_t i = 0; i < players; i++)
	{
		prevValues.insert_or_assign(i, std::map<std::string, std::string>{});
	}
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

void HudVisitor::Visit(std::vector<PlayableCharacter*> characters)
{
	for (int i = 0; i < players; i++)
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
		if (to_string(wRounds) != PrevMapValue(i, "wRounds" + to_string(i)) || wName != PrevMapValue(i, "wName" + to_string(i)))
		{
			const string m_sRounds = to_string(wRounds);
			if (wRounds != INT_MAX)
			{
				if(ammoTextPairs[i].first != infiniteSign)
					SDL_DestroyTexture(ammoTextPairs[i].first);

				string m_sAmmo = "";
				for (size_t i = 0; i < (ammoFixedSize - m_sRounds.size()); i++)
				{
					m_sAmmo += "0";
				}

				m_sAmmo += m_sRounds;
				ammoTextPairs[i] = TextureFactory::CreateText(m_sAmmo, SDL_Point{ bloodRect.x + bloodRect.w - 45, bloodRect.y + horizontalPadding });
			}
			else
			{
				//Render infinite sign
				ammoTextPairs[i].first = infiniteSign;
				ammoTextPairs[i].second = SDL_Rect{ bloodRect.x + bloodRect.w - 32, bloodRect.y + verticalPadding, 24, 13 };
			}
			prevValues.at(i).insert_or_assign("wRounds" + to_string(i), m_sRounds);
		}

		// === Make Weapon Text Texture
		if (wName != PrevMapValue(i, "wName" + to_string(i)))
		{
			const int weaponsSize = characters.at(i)->AmountOfWeapons();
			const int currentWeapIndex = characters.at(i)->CurrentWeaponIndex() + 1;

			SDL_DestroyTexture(weaponTextPairs[i].first);

			const string weaponDetails = weapon->GetName() + " " + to_string(currentWeapIndex) + "/" + to_string(weaponsSize);
			weaponTextPairs[i] = TextureFactory::CreateText(weaponDetails, SDL_Point{ bloodRect.x + horizontalPadding , bloodRect.y });
			weaponTextPairs[i].second.y -= weaponTextPairs[i].second.h;

			//Set Weapon image rectangle 
			weaponImageSrcRect = weapon->GetHudSourceRect();
			weaponImagePair.second = SDL_Rect{
				bloodRect.x + bloodRect.w - horizontalPadding - 110,
				bloodRect.y - horizontalPadding - 40,
				110,
				40
			};

			prevValues.at(i).insert_or_assign("wName" + to_string(i), weapon->GetName());
		}

		if (weaponTextPairs[i].first != nullptr)
			SDL_RenderCopy(renderer, weaponTextPairs[i].first, 0, &weaponTextPairs[i].second);

		if (ammoTextPairs[i].first != nullptr)
			SDL_RenderCopy(renderer, ammoTextPairs[i].first, 0, &ammoTextPairs[i].second);

		if (weaponImagePair.first != nullptr)
			SDL_RenderCopy(renderer, weaponImagePair.first, &weaponImageSrcRect, &weaponImagePair.second);

	}
}

void HudVisitor::Visit(SpawnController & spawnController, GameType& gameType)
{
	if (spawnController.WaveCompleted() && spawnController.LastWave() == false)
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
	const string curWave = std::to_string(spawnController.CurrentWave());

	string waveText = "Wave " + curWave;
	if (gameType != GameType::INFINITY_MODE)
		waveText += "/" + std::to_string(spawnController.Waves());
	waveTextPair = TextureFactory::CreateText(waveText, SDL_Point{ bloodRect.x + horizontalPadding, bloodRect.y + verticalPadding });

	if (waveTextPair.first != nullptr)
		SDL_RenderCopy(renderer, waveTextPair.first, 0, &waveTextPair.second);

	SDL_DestroyTexture(waveTextPair.first);
}

std::string const HudVisitor::PrevMapValue(int i, std::string index)
{
	if (prevValues.size() != 0 && prevValues.at(i).count(index) == 1)//found
		return prevValues.at(i).at(index);
	return "";
}
