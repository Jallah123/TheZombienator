#include "PlayableCharacter.h"
#include "BehaviourFactory.h"
#include "HudDrawBehaviour.h"

PlayableCharacter::PlayableCharacter() : Character()
{
	// this->SetDrawBehaviour("HudDrawBehaviour");
	// this->drawContainer->Add(new HudDrawBehaviour);
}

PlayableCharacter::~PlayableCharacter()
{
	delete weapon;
}
