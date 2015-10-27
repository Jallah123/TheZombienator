#pragma once
#include "Character.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;

class Mike :
	public Character
{
public:
	Mike();//Default constructor
	~Mike();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC, SDL_Renderer* ren);
};

