#include "NormalBulletDrawBehaviour.h"
#include "NormalBullet.h"
#include "PlayableCharacter.h"
#include "MoveDirection.cpp"

NormalBulletDrawBehaviour::NormalBulletDrawBehaviour() : DrawBehaviour()
{
}


NormalBulletDrawBehaviour::~NormalBulletDrawBehaviour()
{
}

void NormalBulletDrawBehaviour::Draw(float dt, SDL_Renderer& ren)
{
	if (!this->gameObject) return;

	NormalBullet* b = dynamic_cast<NormalBullet*>(gameObject);
	MoveDirection md = b->GetOrigin()->GetMoveDir();

	SDL_Rect rect{};
	rect.x = b->GetOrigin()->getPosX() + 16;
	rect.y = b->GetOrigin()->getPosY() + 16;

	SDL_SetRenderDrawColor(&ren, 255, 0, 255, 255);
	rect.h = 10000;
	rect.w = 10000;

	switch (md)
	{
	case MoveDirection::NORTH:
		rect.h = rect.y;
		rect.w = 2;
		rect.y = 0;
		SDL_RenderFillRect(&ren, &rect);
		break;
	case MoveDirection::EAST:
		rect.h = 2;
		SDL_RenderFillRect(&ren, &rect);
		break;
	case MoveDirection::SOUTH:
		rect.w = 2;
		SDL_RenderFillRect(&ren, &rect);
		break;
	case MoveDirection::WEST:
		rect.w = rect.x;
		rect.h = 2;
		rect.x = 0;
		SDL_RenderFillRect(&ren, &rect);
		break;
	case MoveDirection::NONE:
		rect.w = 2;
		SDL_RenderFillRect(&ren, &rect);
		break;
	}
}