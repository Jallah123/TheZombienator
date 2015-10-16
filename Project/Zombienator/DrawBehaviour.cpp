#include "DrawBehaviour.h"
#include "Character.h"

DrawBehaviour::DrawBehaviour() : Behaviour()
{
}


DrawBehaviour::~DrawBehaviour()
{
}

void DrawBehaviour::Draw(float dt, SDL_Renderer & ren)
{
	if (!this->gameObject) return;
	//Do casting here:
	Character* c = dynamic_cast<Character*>(gameObject);
	SDL_RenderCopy(&ren, c->GetTexture(), &c->GetSourceRect(), &c->GetDestinationRect());
}

