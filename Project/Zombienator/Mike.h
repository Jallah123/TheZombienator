#pragma once
#include "PlayableCharacter.h"
#include <string>

class AnimateContainer;
class DrawContainer;
class MoveContainer;
class InputContainer;
class ActionContainer;
class GameObjectContainer;

class Mike :
	public PlayableCharacter
{
public:
	//=== Constructors
	Mike();
	Mike(DrawContainer* drawC, AnimateContainer* animC, MoveContainer* moveC, CollideContainer* collideC, ActionContainer* actionC, GameObjectContainer* gameObjectC);
	void Init(string img_url);
	~Mike();
};

