#include "BazookaBullet.h"
#include "TextureFactory.h"
#include "GameScreen.h"
#include "PlayableCharacter.h"
BazookaBullet::BazookaBullet()
{
	this->texture = TextureFactory::CreateTexture("assets/images/weapons/bullet.png");
	this->SetSize(20, 14);
}

void BazookaBullet::ShakeScreen()
{
	PlayableCharacter* pc = dynamic_cast<PlayableCharacter*>(GetOrigin());
	GameScreen* gameScreen = pc->GetGameScreen();
	gameScreen->Shake(20,5);
}


BazookaBullet::~BazookaBullet()
{
}

void BazookaBullet::SetBehaviours()
{
	SetDrawBehaviour("MovingBulletDrawBehaviour");
	SetMoveBehaviour("BulletMoveBehaviour");
	SetCollideBehaviour("MovingBulletCollideBehaviour");
}
