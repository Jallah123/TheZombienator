#include "BazookaBullet.h"
#include "TextureFactory.h"
#include "GameScreen.h"

BazookaBullet::BazookaBullet()
{
	this->texture = TextureFactory::GenerateTextureFromImgUrl("assets/images/bullet.png");
	this->SetSize(20, 14);
}

void BazookaBullet::ShakeScreen()
{
	GameScreen* gameScreen = this->GetOrigin()->GetGameScreen();
	gameScreen->Shake(20,5);
	gameScreen = nullptr;
	delete gameScreen;
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
