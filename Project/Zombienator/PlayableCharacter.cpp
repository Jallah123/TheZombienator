#include "PlayableCharacter.h"
#include "BehaviourFactory.h"
#include "HudDrawbehaviour.h"

PlayableCharacter::PlayableCharacter() : Character()
{
	this->hudDrawBehaviour = new HudDrawBehaviour;
}

PlayableCharacter::~PlayableCharacter()
{
	delete weapon;
}
