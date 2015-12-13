#include "Weapon.h"
#include "TextureFactory.h"
#include "Settings.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string imagePath)
{
	hudTexture = TextureFactory::GenerateTextureFromImgUrl(imagePath);
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
