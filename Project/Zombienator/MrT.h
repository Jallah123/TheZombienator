#pragma once
#include "PlayableCharacter.h"

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;
class GameObjectContainer;

class MrT :
	public PlayableCharacter
{
public:
	MrT();
	void Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer * actionC, CollideContainer* collideC, GameObjectContainer * gameObjectC, SDL_Renderer * ren, string img_url);
	//Default constructor
	~MrT();
};

