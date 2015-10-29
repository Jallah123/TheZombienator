#include "PlayableCharacter.h"



PlayableCharacter::PlayableCharacter() : Character()
{
}


PlayableCharacter::~PlayableCharacter()
{
	delete weapon;
}
