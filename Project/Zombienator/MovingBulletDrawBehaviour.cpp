#include "MovingBulletDrawBehaviour.h"



MovingBulletDrawBehaviour::MovingBulletDrawBehaviour()
{
}


MovingBulletDrawBehaviour::~MovingBulletDrawBehaviour()
{
}

void MovingBulletDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	Direction d = this->gameObject->GetMoveDir();
	if (d == NONE)
		d = this->gameObject->GetLookDir();
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	double angle = 0;
	switch (d)
	{
		case SOUTHWEST:
			angle = 315;
			break;
		case SOUTH:
			angle = 270;
			break;
		case SOUTHEAST:
			angle = 45;
			flipType = SDL_FLIP_HORIZONTAL;
			break;
		case EAST:
			flipType = SDL_FLIP_HORIZONTAL;
			break;
		case NORTHEAST:
			angle = -45;
			flipType = SDL_FLIP_HORIZONTAL;
			break;
		case NORTH:
			angle = 90;
			break;
		case NORTHWEST:
			angle = 45;
			break;
		case WEST:
			angle = 0;
			break;
	}

	gameObject->GetDestinationRect()->x += XOffset;
	gameObject->GetDestinationRect()->y += YOffset;
	SDL_RenderCopyEx(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect(), angle, NULL, flipType);
}
