#pragma once
#include "PlayableCharacter.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;
class CharacterContainer;

class Mike :
	public PlayableCharacter
{
public:
	Mike();
	void Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer * actionC, CharacterContainer * characterC, SDL_Renderer * ren);
	//Default constructor
	~Mike();
};

