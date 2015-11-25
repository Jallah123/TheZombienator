#include "NormalBulletDrawBehaviour.h"
#include "NormalBullet.h"
#include "PlayableCharacter.h"
#include "Direction.cpp"

NormalBulletDrawBehaviour::NormalBulletDrawBehaviour() : DrawBehaviour()
{
}


NormalBulletDrawBehaviour::~NormalBulletDrawBehaviour()
{
}

void NormalBulletDrawBehaviour::Draw(float dt, SDL_Renderer& ren, int XOffset, int YOffset)
{
	if (!this->gameObject) {
		return;
	}
	
	NormalBullet* b = dynamic_cast<NormalBullet*>(gameObject);
	Character* origin = b->GetOrigin();
	SDL_Rect* target = b->GetTarget();
	Direction md = b->GetLookDir();
	SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);
	SDL_Point* end = b->GetEndPoint();
	
	std::cout << "collision ? " << b->HasCollision() << "\n";
	std::cout << "target ? " << (target == nullptr) << "\n";
	end->x = b->HasCollision() ? target->x : end->x;
	end->y = b->HasCollision() ? target->y : end->y;
		
	b->SetDirection(md);

	
	rect.x -= XOffset;
	rect.y -= YOffset;
	b->SetDestinationRect(rect);
	
	if (b->IsLocked()) {
		//SDL_RenderFillRect(&ren, &rect);
		SDL_RenderDrawLine(&ren, origin->getPosX(), origin->getPosY(), end->x, end->y);
		b->DecreaseLifeTime(dt);
	}
	
	if (b->GetLifeTime() <= 0) CanRemove(true);
	
	b->SetLocked(true);
}