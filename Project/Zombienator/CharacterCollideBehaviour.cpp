#include "CharacterCollideBehaviour.h"
#include "Character.h"
#include "CharacterContainer.h"

CharacterCollideBehaviour::CharacterCollideBehaviour()
{
}


CharacterCollideBehaviour::~CharacterCollideBehaviour()
{
}

void CharacterCollideBehaviour::Collide(float dt)
{
	/*for (auto& r : collisionLayer->GetRects()) {
		if(SDL_HasIntersection(this->gameObject->GetDestinationRect(), r)) {
			std::cout << "Collides a rect "<< this->gameObject << std::endl;
			//c->SetMoveDir(Direction::NONE);
			this->gameObject->CanMove(false);
			//Stop(this->gameObject, r);
		}
	}

	std::vector<Character*> characters = characterContainer->GetCharacters();
	for (auto& c : characters)
	{	
		if (SDL_HasIntersection(this->gameObject->GetDestinationRect(), c->GetDestinationRect()))
		{
			//c->SetMoveDir(Direction::NONE);
			//c->SetMoveDir(Direction::NONE);
		}
	}*/
}

void CharacterCollideBehaviour::Stop(GameObject* c, SDL_Rect* rect)
{
	Direction ld = c->GetLookDir();
	int goh = c->GetHeight();
	int gow = c->GetWidth();
	switch (ld)
	{
	case SOUTH:
		c->SetPosition(c->getPosX(), (rect->y - 1) - goh);
		break;
	case EAST:
		c->SetPosition((rect->x - 1) - gow, c->getPosY());
		break;
	case NORTH:
		c->SetPosition(c->getPosX(), ((rect->y+rect->h) +1));
		break;
	case WEST:
		c->SetPosition(((rect->x + rect->w) + 1) - gow, c->getPosY());
		break;
	}

}
