#pragma once
#include <SDL_image.h>
#include <string>
#include <map>
#include <vector>

class PlayableCharacter;
class Weapon;
class SpawnController;
enum GameType;
struct SDL_Rect;
using std::pair;
using std::vector;
class HudVisitor
{
private:
	int horizontalPadding = 6;
	int verticalPadding = 9;
	size_t players = 1;
	SDL_Renderer* renderer = nullptr;

	pair<SDL_Texture*, SDL_Rect> weaponImagePair = {};
	SDL_Rect weaponImageSrcRect = { 0,0,0,0 };
	vector<pair<SDL_Texture*, SDL_Rect>> weaponTextPairs = {};
	vector<pair<SDL_Texture*, SDL_Rect>> ammoTextPairs = {};
	pair<SDL_Texture*, SDL_Rect> waveTextPair = {};
	pair<SDL_Texture*, SDL_Rect> countDownTextPair = {};
	

	SDL_Texture* bloodHud = nullptr;
	SDL_Texture* infiniteSign = nullptr;
	SDL_Rect bloodRect = { 0,0,289,13 };

	std::map<int, std::map<std::string, std::string>> prevValues = {};

	std::string countdown;

	SDL_Rect bounds = {0,0,0,0};
	size_t ammoFixedSize = 3;
public:
	HudVisitor() {};
	HudVisitor(SDL_Renderer* _renderer, SDL_Rect bounds, size_t players);
	~HudVisitor();

	void DrawBase();
	void Visit(std::vector<PlayableCharacter*> characters);
	void Visit(SpawnController& spawnController, GameType& gameType);
	
	std::string const PrevMapValue(int i, std::string index);
};

