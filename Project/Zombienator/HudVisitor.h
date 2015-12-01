#pragma once
#include <SDL_image.h>
#include <string>

class Character;
class Weapon;
class HudVisitor
{
private:
	SDL_Renderer* renderer;
	SDL_Texture* weaponNameTexture{ nullptr };
	std::string weaponName = "";
public:
	HudVisitor() {};
	HudVisitor(SDL_Renderer* _renderer);
	void DrawBase();
	void Visit(Character* character);
	void Visit(Weapon* weapon);
	~HudVisitor();
};

