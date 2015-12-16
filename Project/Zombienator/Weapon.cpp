#include "Weapon.h"
#include "TextureFactory.h"
#include "Settings.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string imagePath)
{
	hudTexture = TextureFactory::CreateTexture(imagePath);
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
