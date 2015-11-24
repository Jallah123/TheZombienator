#include "Weapon.h"
#include "TextureFactory.h"

Weapon::Weapon(std::string imagePath)
{
	hudTexture = TextureFactory::GenerateTextureFromImgUrl(imagePath);
}


Weapon::~Weapon()
{
}
