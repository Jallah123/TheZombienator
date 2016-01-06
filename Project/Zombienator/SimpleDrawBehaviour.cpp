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
	gameObject->GetDestinationRect()->x += XOffset;
	gameObject->GetDestinationRect()->y += YOffset;
	SDL_RenderCopy(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect());
}
