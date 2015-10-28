#include "CharacterDrawBehaviour.h"
#include "Character.h"

CharacterDrawBehaviour::CharacterDrawBehaviour()
{
}


CharacterDrawBehaviour::~CharacterDrawBehaviour()
{
}

void CharacterDrawBehaviour::Draw(float dt, SDL_Renderer & ren)
{
		if (!this->gameObject) return;
		//Do casting here:
		Character* c = dynamic_cast<Character*>(gameObject);
		SDL_RenderCopy(&ren, c->GetTexture(), &c->GetSourceRect(), &c->GetDestinationRect());
		SDL_RenderFillRect(&ren, &c->GetDestinationRect());
}
