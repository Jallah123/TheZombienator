#include "MovingBulletDrawBehaviour.h"



MovingBulletDrawBehaviour::MovingBulletDrawBehaviour()
{
}


MovingBulletDrawBehaviour::~MovingBulletDrawBehaviour()
{
}

void MovingBulletDrawBehaviour::Draw(float dt, SDL_Renderer & ren, int XOffset, int YOffset)
{
	Direction d = this->gameObject->GetLookDir();
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	double angle = 0;
	switch (d)
	{
	case SOUTH:
		angle = 270;
		break;
	case EAST:
		flipType = SDL_FLIP_HORIZONTAL;
		break;
	case NORTH:
		angle = 90;
		break;
	case WEST:
		angle = 0;
		break;
	}

	SDL_RenderCopyEx(&ren, gameObject->GetTexture(), gameObject->GetSourceRect(), gameObject->GetDestinationRect(), angle, NULL, flipType);
}
