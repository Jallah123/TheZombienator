#include "MineBullet.h"
#include "TextureFactory.h"
#include "GameScreen.h"

MineBullet::MineBullet()
{
	this->texture = TextureFactory::CreateTexture("assets/images/MineBullet.png");
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
	GameScreen* gameScreen = this->GetOrigin()->GetGameScreen();
	gameScreen->Shake(50, 15);
}

void MineBullet::SetBehaviours()
{
	SetDrawBehaviour("SimpleDrawBehaviour");
	SetCollideBehaviour("NonMovingBulletCollideBehaviour");
}
