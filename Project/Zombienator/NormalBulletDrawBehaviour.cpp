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

void NormalBulletDrawBehaviour::Draw(float dt, SDL_Renderer& ren)
{
	if (!this->gameObject) {
		return;
	}
	
	NormalBullet* b = dynamic_cast<NormalBullet*>(gameObject);
	Character* origin = b->GetOrigin();
	SDL_Rect* target = b->GetTarget();
	Direction md = b->GetLookDir();
	SDL_SetRenderDrawColor(&ren, 0, 0, 0, 255);
	SDL_Point end = { origin->getPosX(), origin->getPosY() };
	//if(b->HasCollision())
		//std::cout << "x:" << target->x << ", y:" << target->y << ", w:" << target->w << ", h:" << target->h;
	/*switch (md)
	{
	case SOUTH:
		end.x = target->x;
		end.y = target->y;

		rect.x = b->getPosX() + offsetX;
		rect.y = (b->getPosY() + offsetY) + origin->GetHeight();
		rect.w = 2;
		rect.h = b->HasCollision() ? (target->y - b->getPosY()) - target->h : maxLength;
		break;
	case EAST:
		rect.x = b->getPosX() + origin->GetWidth() + offsetX;
		rect.y = b->getPosY() + (origin->GetHeight() / 2);
		rect.w = b->HasCollision() ? (target->x - b->getPosX()) - target->w : maxLength;
		rect.h = 2;
		break;
	case NORTH:
		rect.x = b->getPosX() + (origin->GetWidth() - offsetX);
		rect.y = b->HasCollision() ? target->y + (target->h / 2) : 0;
		rect.w = 2;
		rect.h = b->HasCollision() ? (origin->getPosY() - target->y) : b->getPosY() - offsetY;
		break;
	case WEST:
		rect.x = b->HasCollision() ? (target->x + target->w) : 0;
		rect.y = b->getPosY() + (origin->GetHeight() / 2);
		rect.w = b->HasCollision() ? (b->getPosX() - target->x) - target->w : b->getPosX() - offsetX;
		rect.h = 2;
		break;
	case NONE:
		break;
	}*/
	
		end.x = b->HasCollision() ? target->x : 0 ;
		end.y = b->HasCollision() ? target->y : 0;
		SDL_RenderDrawLine(&ren, origin->getPosX(), origin->getPosY(), end.x, end.y);

	b->SetDirection(md);

	b->SetDestinationRect(rect);
	
	if (b->IsLocked()) {
		
		//SDL_RenderFillRect(&ren, &rect);
	}
	b->DecreaseLifeTime(dt);
	b->SetLocked(true);
}