#include "BadassZombie.h"
#include "GameObjectFactory.h"



BadassZombie::BadassZombie() : Zombie()
{
}

BadassZombie::BadassZombie(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: Zombie(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
}


BadassZombie::~BadassZombie()
{
}

void BadassZombie::Init()
{
	SetImage(basePath + "7zombie.png");
	SetNormalTexture(basePath + "7zombie.png");
	SetAttackTexture(basePath + "7zombie.png");

	SetDeadTexture(basePath + "explosion.png");

	this->SetSize(46, 46);

	SetFrames(3);
	SetSpeed(0.4f);

	SetMaxHealth(200);
	SetHealth(200);

	SetAttackDamage(20);
	SetAttackSpeed(2);

	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

}

void BadassZombie::OnDeath()
{
	GameObjectFactory::Instance()->CreateAmmoBox(this);
}
