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
	if (!this->gameObject) {
		return;
	}

	NormalBullet* b = dynamic_cast<NormalBullet*>(gameObject);
	Character* origin = b->GetOrigin();
	Character* target = b->GetTarget();
	MoveDirection md = b->GetMoveDir();
	SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);

	switch (md)
	{
	case MoveDirection::NORTH:
		rect.x = b->getPosX() + (origin->GetWidth() - offsetX);
		rect.y = b->HasCollision() ? target->getPosY() + (target->GetHeight() / 2) : 0;
		rect.w = 2;
		rect.h = b->HasCollision() ? (origin->getPosY() - target->getPosY()) : b->getPosY() - offsetY;
		break;
	case MoveDirection::EAST:
		rect.x = b->getPosX() + origin->GetWidth() + offsetX;
		rect.y = b->getPosY() + (origin->GetHeight() / 2);
		rect.w = b->HasCollision() ? (target->getPosX() - b->getPosX()) - target->GetWidth() : maxLength;
		rect.h = 2;
		break;
	case MoveDirection::SOUTH:
	case MoveDirection::NONE:
		rect.x = b->getPosX() + offsetX;
		rect.y = (b->getPosY() + offsetY) + origin->GetHeight();
		rect.w = 2;
		rect.h = b->HasCollision() ? (target->getPosY() - b->getPosY()) - target->GetHeight() : maxLength;
		break;
	case MoveDirection::WEST:
		rect.x = b->HasCollision() ? (target->getPosX() + target->GetWidth()) : 0;
		rect.y = b->getPosY() + (origin->GetHeight() / 2);
		rect.w = b->HasCollision() ? (b->getPosX() - target->getPosX()) - target->GetWidth() : b->getPosX() - offsetX;
		rect.h = 2;

		break;
			
	}
	b->SetLocked(true);
	b->SetDestinationRect(rect);
	
	if (b->IsLocked() && b->HasCollision()) {
		SDL_RenderFillRect(&ren, &rect);
	}
	b->DecreaseLifeTime(dt);
	//std::cout << dt << std::endl;
	//std::cout << b->IsLocked() << std::endl;
	//b->SetLocked(true);
}