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
	if (b->GetLifeTime() <= 0) {
		b->Remove();
		return;
	}
	
	SDL_Point* begin = b->GetBeginPoint();
	b->CalculateEndPoint();
	SDL_Point* end = b->GetEndPoint();
		
	
	if (b->IsLocked()) {
		SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);
		SDL_RenderDrawLine(&ren, begin->x - XOffset, begin->y - YOffset, end->x - XOffset, end->y - YOffset);
		b->DecreaseLifeTime(dt);
	}
	b->SetLocked(true);
	
}