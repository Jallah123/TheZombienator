#include "Weapon.h"
#include "TextureFactory.h"
#include "Settings.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string name, int rounds, int maxRounds, int delay, int damage, std::string bulletType, SDL_Rect srcRect) : 
	name{ name },
	rounds{ rounds },
	maxRounds{ maxRounds },
	delay{ delay },
	damage{ damage },
	bulletType{ bulletType }
{
	hudSourceRect = srcRect;
}


void Weapon::Fire()
{
	if (!Settings::GetInstance().getInfiniteAmmo())
	{
		if (rounds != 0)
		{
			rounds--;
		}
	}
}


Weapon::~Weapon()
{
}
