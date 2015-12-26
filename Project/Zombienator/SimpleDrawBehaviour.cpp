#include "SimpleDrawBehaviour.h"
#include "GameObject.h"


SimpleDrawBehaviour::SimpleDrawBehaviour()
{
}


SimpleDrawBehaviour::~SimpleDrawBehaviour()
{
}

void SimpleDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	SDL_RenderCopy(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect());
}
