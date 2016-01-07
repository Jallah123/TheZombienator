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
	if (!this->gameObject) {
		return;
	}

	float newX = gameObject->getPosX();
	float newY = gameObject->getPosY();

	gameObject->SetPosition(newX, newY);

	gameObject->GetDestinationRect()->x += XOffset;
	gameObject->GetDestinationRect()->y += YOffset;

	SDL_RenderCopy(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect());
}
