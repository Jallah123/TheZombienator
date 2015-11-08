#include "CharacterCollideBehaviour.h"
#include "Character.h"
#include "CharacterContainer.h"

CharacterCollideBehaviour::CharacterCollideBehaviour()
{
}


CharacterCollideBehaviour::~CharacterCollideBehaviour()
{
}

bool CharacterCollideBehaviour::Collide(float dt)
{
	Character* _this = dynamic_cast<Character*>(this->gameObject);
	std::vector<Character*> characters = characterContainer->GetCharacters();
	for (auto& c : characters)
	{
		
		if (SDL_HasIntersection(_this->GetDestinationRect(), c->GetDestinationRect()))
		{
			return true;
		}
	}
	return false;
}