#include "CharacterDrawBehaviour.h"
#include "Character.h"

CharacterDrawBehaviour::CharacterDrawBehaviour()
{
}


CharacterDrawBehaviour::~CharacterDrawBehaviour()
{
}

void CharacterDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
		if (!this->gameObject) return;
		//Do casting here:
		Character* c = dynamic_cast<Character*>(gameObject);
		SDL_Rect Destination = *c->GetDestinationRect();
		Destination.x -= XOffset;
		Destination.y -= YOffset;
		SDL_RenderCopy(&ren, c->GetTexture(), &c->GetSourceRect(), &Destination);
}
