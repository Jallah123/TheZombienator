#pragma once
#include "Character.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;

class Zombie :
	public Character
{
/*private:
	Character* target;//Mike||Arnold*/
public:
	Zombie();
	~Zombie();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, SDL_Renderer* ren);
};

