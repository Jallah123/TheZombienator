#pragma once
#include "DrawBehaviour.h"

class HudDrawBehaviour :
	public DrawBehaviour
{
public:
	HudDrawBehaviour(GameObject* _gameObject);
	void Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset);
	~HudDrawBehaviour();
private:
	SDL_Texture* weaponNameTexture{ nullptr };
	string weaponName = "";

};

