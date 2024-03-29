#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "GameObjectContainer.h"
#include "Zombie.h"

NormalBullet::NormalBullet()
{
	begin = new SDL_Point();
	end = new SDL_Point();
}


NormalBullet::~NormalBullet()
{
	delete end;
	delete begin;
}

void NormalBullet::SetBehaviours()
{
	SetDrawBehaviour("NormalBulletDrawBehaviour");
	SetCollideBehaviour("NormalBulletCollideBehaviour");
}

void NormalBullet::CalculateEndPoint()
{
	SDL_Rect r = gameObjectContainer->GetBounds();
	bool isZombie = dynamic_cast<Zombie*>(target) != nullptr ? true : false;
	if (isZombie) {
		SDL_Rect* tr = target->GetDestinationRect();
		end->x = tr->x + (tr->w / 2);
		end->y = tr->y + (tr->h / 2);
		return;
	}

	SDL_Point start = *GetBeginPoint();

	auto diagonal = min(start.x, start.y);

	Direction d = this->moveDir;
	if (d == NONE)
		d = this->GetLookDir();

	switch (d)
	{	
		case NORTHWEST:
			end->x = start.x - diagonal;
			end->y = start.y - diagonal;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x + (tr->w / 2);
				end->y = tr->y + (tr->h / 2);
			}
			break;
		case SOUTHWEST: 
			end->x = start.x - diagonal;
			end->y = start.y + diagonal;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x + (tr->w / 2);
				end->y = tr->y + (tr->h / 2);
			}
			break;
		case NORTHEAST:	
			end->x = start.x + diagonal;
			end->y = start.y - diagonal;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x + (tr->w / 2);
				end->y = tr->y + (tr->h / 2);
			}
			break;
		case SOUTHEAST: 
			end->x = start.x + diagonal;
			end->y = start.y + diagonal;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x + (tr->w / 2);
				end->y = tr->y + (tr->h / 2);
			}
			break;
		case SOUTH:
			end->x = origin->getPosX() + xFrontOffset;
			end->y = r.h;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->y = tr->y;
			}
			break;
		case EAST:
			end->x = r.w;
			end->y = origin->getPosY() + origin->GetHeight() - ySideOffset;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x;
			}
			break;
		case NORTH:
			end->x = origin->getPosX() + origin->GetWidth() - xFrontOffset;
			end->y = r.y;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->y = tr->y + tr->h;
			}
			break;
		case WEST:
			end->x = r.x;
			end->y = origin->getPosY() + origin->GetHeight() - ySideOffset;
			if (HasCollision()) {
				SDL_Rect* tr = target->GetDestinationRect();
				end->x = tr->x + tr->w;
			}
			break;
	}
}

SDL_Point * NormalBullet::GetBeginPoint()
{	
	Direction d = this->moveDir;
	if (d == NONE)
		d = this->GetLookDir();
	
	switch (d)
	{	
		case SOUTH:
		case SOUTHWEST:
			begin->x = origin->getPosX() + xFrontOffset;
			begin->y = origin->getPosY() + origin->GetHeight() - yFrontOffset;
			break;
		case EAST:
		case NORTHEAST:
		case SOUTHEAST:
			begin->x = origin->getPosX() + (origin->GetWidth() /2) + xSideOffset;
			begin->y = origin->getPosY() + origin->GetHeight() - ySideOffset;
			break;
		case NORTH:
			begin->x = origin->getPosX() + origin->GetWidth() - xFrontOffset;
			begin->y = origin->getPosY() + origin->GetHeight() - yFrontOffset;
			break;
		case WEST:
		case NORTHWEST:
			begin->x = origin->getPosX() + (origin->GetWidth() / 2) - xSideOffset;
			begin->y = origin->getPosY() + origin->GetHeight() - ySideOffset;
			break;
		}
	return begin;
}

