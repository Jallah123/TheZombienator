#pragma once
#include <SDL_image.h>
#include <string>
#include <map>

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

	SDL_Texture* weaponSpritesheet = nullptr;
	std::pair<SDL_Texture*, SDL_Rect> weaponTextPair = {};
	std::pair<SDL_Texture*, SDL_Rect> ammoTextPair = {};
	std::pair<SDL_Texture*, SDL_Rect> waveTextPair = {};
	

	SDL_Texture* bloodHud = nullptr;
	SDL_Texture* infiniteSign = nullptr;
	SDL_Rect bloodRect = { 0,0,289,13 };

	std::map<std::string, std::string> prevValues = {};

	SDL_Rect bounds = {0,0,0,0};
	int players = 1;
	size_t ammoFixedSize = 3;
public:
	HudVisitor() {};
	HudVisitor(SDL_Renderer* _renderer, SDL_Rect bounds);
	~HudVisitor();

	void DrawBase();
	void Visit(PlayableCharacter& character);
	void Visit(SpawnController& spawnController);
	
	std::string const PrevMapValue(std::string index);
};

