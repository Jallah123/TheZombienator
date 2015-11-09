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
	Character* c = dynamic_cast<Character*>(this->gameObject);
	std::vector<Character*> characters = characterContainer->GetCharacters();
	for (const auto& r : collisionLayer->GetRects()) {
		if(SDL_HasIntersection(c->GetDestinationRect(), r)) {
			std::cout << "Collides a rect" << std::endl;
			//c->SetMoveDir(Direction::NONE);
		}
	}
	for (auto& c : characters)
	{	
		if (SDL_HasIntersection(c->GetDestinationRect(), c->GetDestinationRect()))
		{
			//c->SetMoveDir(Direction::NONE);
		}
	}
	return false;
}
