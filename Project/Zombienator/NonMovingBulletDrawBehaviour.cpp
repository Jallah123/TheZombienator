#include "NonMovingBulletDrawBehaviour.h"
#include "NormalBullet.h"
#include "PlayableCharacter.h"
#include "Direction.cpp"

NonMovingBulletDrawBehaviour::NonMovingBulletDrawBehaviour() : DrawBehaviour()
{
}


NonMovingBulletDrawBehaviour::~NonMovingBulletDrawBehaviour()
{
}

void NonMovingBulletDrawBehaviour::Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset)
{
	if (!this->gameObject) {
		return;
	}

	float newX = gameObject->getPosX();
	float newY = gameObject->getPosY();

	gameObject->SetPosition(newX, newY);

	SDL_RenderCopy(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect());
}