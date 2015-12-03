#include "Zombie.h"
#include "GameObjectContainer.h"
#include "ZombieStateFactory.h"
#include "ZombieAttackState.h"
#include "NumberUtility.h"
#include <string>
#include "TextureFactory.h"
#include "GameMath.h"
using std::string;

Zombie::Zombie() : Character() 
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}

Zombie::~Zombie() {}

void Zombie::Init(DrawContainer * drawC, AnimateContainer * animC, MoveContainer * moveC, ActionContainer* actionC, CollideContainer* collideC, GameObjectContainer* gameObjectC, SDL_Renderer* ren)
{
	//Zombie doesn't have input from the InputContainer	
	int dice_roll = NumberUtility::RandomNumber(1, 6);

	string basePath = "assets/images/spritesheets/";
	string baseAttackPath = "assets/images/spritesheets/attack/";
	string spriteSheet = std::to_string(dice_roll) + "zombie.png";

	SetImage(basePath + spriteSheet, *ren);
	SetNormalTexture(basePath + spriteSheet);
	SetAttackTexture(baseAttackPath + spriteSheet);
	this->SetContainers(drawC, animC, moveC, nullptr, nullptr, collideC, gameObjectC);
	SetDrawBehaviour("CharacterDrawBehaviour");
	SetAnimateBehaviour("AnimateBehaviour");
	SetCollideBehaviour("CharacterCollideBehaviour");

	gameObjectC->AddGameObject(this);
	
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
