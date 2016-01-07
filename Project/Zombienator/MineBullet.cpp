#include "MineBullet.h"
#include "TextureFactory.h"
#include "GameScreen.h"

MineBullet::MineBullet()
{
	this->texture = TextureFactory::CreateTexture("assets/images/weapons/MineBullet.png");
	this->SetSize(30, 30);
	this->SetCollideable(false);
}


MineBullet::~MineBullet()
{
}

void MineBullet::Hit()
{
	SoundController::GetInstance().PlaySound("assets/sounds/explosion.wav", 0);
}

void MineBullet::ShakeScreen()
{
	PlayableCharacter* pc = dynamic_cast<PlayableCharacter*>(GetOrigin());

	GameScreen* gameScreen = pc->GetGameScreen();
	gameScreen->Shake(50, 15);
}

void MineBullet::SetBehaviours()
{
	SetDrawBehaviour("SimpleDrawBehaviour");
	SetCollideBehaviour("NonMovingBulletCollideBehaviour");
}
