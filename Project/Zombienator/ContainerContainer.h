#pragma once
#include "ActionContainer.h"
#include "AnimateContainer.h"
#include "CharacterContainer.h"
#include "CollideContainer.h"
#include "DrawContainer.h"
#include "MoveContainer.h"

class ContainerContainer
{
public:
	static ContainerContainer& GetInstance() {
		static ContainerContainer instance;
		return instance;
	};
	ActionContainer* GetActionContainer() { return &actionContainer; }
	AnimateContainer* GetAnimateContainer() { return &animateContainer; }
	CharacterContainer* GetCharacterContainer() { return &characterContainer; }
	CollideContainer* GetCollideContainer() { return &collideContainer; }
	DrawContainer* GetDrawContainer() { return &drawContainer; }
	MoveContainer* GetMoveContainer() { return &moveContainer; }
private:
	ContainerContainer();
	~ContainerContainer();
	ActionContainer actionContainer;
	AnimateContainer animateContainer;
	CharacterContainer characterContainer;
	CollideContainer collideContainer;
	DrawContainer drawContainer;
	MoveContainer moveContainer;
};

