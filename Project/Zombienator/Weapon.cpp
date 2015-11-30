#include "Weapon.h"
#include "TextureFactory.h"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string imagePath)
{
	hudTexture = TextureFactory::GenerateTextureFromImgUrl(imagePath);
}


Weapon::~Weapon()
{
}
