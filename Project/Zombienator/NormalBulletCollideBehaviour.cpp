#include "NormalBulletCollideBehaviour.h"
#include "Bullet.h"
#include "PlayableCharacter.h"
#include "ContainerContainer.h"

NormalBulletCollideBehaviour::~NormalBulletCollideBehaviour()
{
}

bool NormalBulletCollideBehaviour::Collide(float dt)
{
	for (auto& c : ContainerContainer::GetInstance().GetCharacterContainer()->GetCharacters()) 
	{
		Bullet* bullet = dynamic_cast<Bullet*>(gameObject);
		if (SDL_HasIntersection(&bullet->GetSourceRect(), &c->GetSourceRect()))
		{
			c->TakeHit(bullet->GetOrigin()->GetWeapon()->GetDamage());
			return true;
		}
	}
	return false;
}
