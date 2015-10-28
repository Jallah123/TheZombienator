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
	Character* origin = b->GetOrigin();
	Character* target = b->GetTarget();
	MoveDirection md = origin->GetMoveDir();

	if (b->IsLocked()) {
		//b->SetDestinationRect(rect);
		SDL_RenderFillRect(&ren, &rect);
	}
	else {
		if (b->HasCollision()) SDL_SetRenderDrawColor(&ren, 5, 0, 255, 128);
		else SDL_SetRenderDrawColor(&ren, 255, 0, 255, 255);
		std::cout << "hasCollision: " << b->HasCollision() << std::endl;
		switch (md)
		{
		case MoveDirection::NORTH:
			rect.x = origin->getPosX() + (origin->GetWidth() - offsetX);
			rect.y = b->HasCollision() ? target->getPosY() + (target->GetHeight() / 2) : 0;
			rect.w = 2;
			rect.h = b->HasCollision() ? (origin->getPosY() - target->getPosY()) : origin->getPosY() - offsetY;
			break;
		case MoveDirection::EAST://Finished
			rect.x = origin->getPosX() + origin->GetWidth() + offsetX;
			rect.y = origin->getPosY() + (origin->GetHeight() / 2);
			rect.w = b->HasCollision() ? (target->getPosX() - origin->getPosX()) - target->GetWidth() : maxLength;
			rect.h = 2;
			break;
		case MoveDirection::SOUTH:
		case MoveDirection::NONE:
			rect.x = origin->getPosX() + offsetX;
			rect.y = (origin->getPosY() + offsetY) + origin->GetHeight();
			rect.w = 2;
			rect.h = b->HasCollision() ? (target->getPosY() - origin->getPosY()) - target->GetHeight() - offsetY : maxLength;
			break;
		case MoveDirection::WEST://
			rect.x = b->HasCollision() ? (target->getPosX() + target->GetWidth()) : 0;
			rect.y = origin->getPosY() + (origin->GetHeight() / 2);
			rect.w = b->HasCollision() ? (origin->getPosX() - target->getPosX()) - target->GetWidth() : origin->getPosX() - offsetX;
			rect.h = 2;

			break;
		}
		b->SetDestinationRect(rect);
		b->SetLocked(true);
	}

	
}