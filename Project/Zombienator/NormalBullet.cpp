#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "GameObjectContainer.h"

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
	switch (this->moveDir)
	{
	case SOUTH:
		end->x = origin->getPosX();
		end->y = r.h;
		break;
	case EAST:
		end->x = r.w;
		end->y = origin->getPosY();
		break;
	case NORTH:
		end->x = origin->getPosX();
		end->y = r.y;
		break;
	case WEST:
		end->x = r.x;
		end->y = origin->getPosY();
		break;
	}
}

SDL_Point * NormalBullet::GetBeginPoint()
{
	begin->x = posX;
	begin->y = posY;
	return begin;
}

