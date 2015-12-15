#include "Zombie.h"
#include "GameObjectContainer.h"
#include "ZombieStateFactory.h"
#include "ZombieAttackState.h"
#include "ZombieDeadState.h"
#include "NumberUtility.h"
#include <string>
#include "TextureFactory.h"
#include "GameMath.h"
using std::string;

Zombie::Zombie() : Character() 
{
	SetCurrentState(ZombieStateFactory::Create(ZombieStateEnum::STANDSTILL, this));
}

Zombie::~Zombie() {
	delete target;
	delete currentState;
	delete normalTexture;
	delete attackTexture;
	delete deadTexture;
}

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
	SetDeadTexture(basePath + "explosion.png");

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
	attackTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}

void Zombie::SetDeadTexture(string path)
{
	deadTexture = TextureFactory::GenerateTextureFromImgUrl(path);
}
