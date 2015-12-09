#include "Zombie.h"
#include "GameObjectContainer.h"
#include "ZombieStateFactory.h"
#include "ZombieAttackState.h"
#include "NumberUtility.h"
#include "TextureFactory.h"
#include "GameMath.h"


Zombie::Zombie() 
	: Character() 
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}

Zombie::Zombie(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, CollideContainer * collideC, ActionContainer * actionC, GameObjectContainer * gameObjectC)
	: Character(drawC, animC, moveC, collideC, actionC, gameObjectC)
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}

Zombie::~Zombie() {}

void Zombie::Init()
{
	//Zombie doesn't have input from the InputContainer	
	int dice_roll = NumberUtility::RandomNumber(1, 6);

	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath + spriteSheet);
	SetNormalTexture(basePath + spriteSheet);
	SetAttackTexture(baseAttackPath + spriteSheet);
	
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectContainer->AddGameObject(this);
	
	SetSize(32, 36);
	SetFrames(3);
	SetSpeed(0.4f);
	SetMaxHealth(50);
	SetHealth(50);

	// -- Zombie Attack
	SetAttackDamage(1);
	SetAttackSpeed(2);
	SetSoundSpeed(2);
}

void Zombie::SetCurrentState(ZombieState* newState)
{	
	
	if(this->currentState != newState)
	{
		if (dynamic_cast<ZombieAttackState*>(newState))
			ChangeTexture(true);
		else
			ChangeTexture(false);
	}
	this->currentState = newState;
}

bool Zombie::IsInAttackRadius(Character * target)
{
	
	double dist = GameMath::Distance(*this->GetCollideRect(), *target->GetCollideRect());
	if (lookDir == Direction::NORTH || lookDir == Direction::SOUTH) {
		return dist < sweetspotY;
	}
	else if (lookDir == Direction::EAST || lookDir == Direction::WEST) {
		return dist < sweetspotX;
	}
	return false;
}

void Zombie::SetNormalTexture(string path)
{
	normalTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void Zombie::SetAttackTexture(string path)
{
	AttackTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void Zombie::ChangeTexture(bool isAttack)
{
	if (isAttack)
		SetTexture(this->AttackTexture);
	else
		SetTexture(this->normalTexture);
}
