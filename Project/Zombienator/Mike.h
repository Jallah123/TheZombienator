#pragma once
#include "PlayableCharacter.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;

class Mike :
	public PlayableCharacter
{
public:
	Mike();//Default constructor
	~Mike();
	void Init(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, ActionContainer* actionC, SDL_Renderer* ren);
};

