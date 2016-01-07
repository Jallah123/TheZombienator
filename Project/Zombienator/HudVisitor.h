#pragma once
#include <SDL_image.h>
#include <string>
#include <map>
#include <vector>

class PlayableCharacter;
class Weapon;
class SpawnController;
struct SDL_Rect;

class HudVisitor
{
private:
	int horizontalPadding = 6;
	int verticalPadding = 9;
	SDL_Renderer* renderer = nullptr;

	std::pair<SDL_Texture*, SDL_Rect> weaponImagePair = {};
	SDL_Rect weaponImageSrcRect = { 0,0,0,0 };
	std::pair<SDL_Texture*, SDL_Rect> weaponTextPair = {};
	std::pair<SDL_Texture*, SDL_Rect> ammoTextPair = {};
	std::pair<SDL_Texture*, SDL_Rect> waveTextPair = {};
	std::pair<SDL_Texture*, SDL_Rect> countDownTextPair = {};
	

	SDL_Texture* bloodHud = nullptr;
	SDL_Texture* infiniteSign = nullptr;
	SDL_Rect bloodRect = { 0,0,289,13 };

	std::map<PlayableCharacter*, std::map<std::string, std::string>> prevValues = {};

	std::string countdown;

	SDL_Rect bounds = {0,0,0,0};
	size_t ammoFixedSize = 3;
public:
	HudVisitor() {};
	HudVisitor(SDL_Renderer* _renderer, SDL_Rect bounds);
	~HudVisitor();

	void DrawBase(int players);
	void Visit(std::vector<PlayableCharacter*> characters);
	void Visit(SpawnController& spawnController);
	
	std::string const PrevMapValue(PlayableCharacter* character, std::string index);
};

