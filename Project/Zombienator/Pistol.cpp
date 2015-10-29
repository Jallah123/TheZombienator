#pragma once
#include "Pistol.h"
#include <limits>
#include <iostream>
#include "BulletFactory.h"
#include "NormalBullet.h"
#include "BehaviourFactory.h"
#include "ContainerContainer.h"

Pistol::Pistol() : Weapon()
{
	this->rounds = INT_MAX;
	this->delay = 20;
	this->damage = 20;  // 1/5 of a zombie's health
	this->bulletType = "bullet";
	BulletFactory::Instance()->Register(bulletType, [](void) -> Bullet* { return new NormalBullet(); });
}


Pistol::~Pistol()
{
}

void Pistol::Fire()
{
	NormalBullet* b = BulletFactory::Instance()->CreateNormalBullet(this->character);
	b->SetContainers(ContainerContainer::GetInstance().GetDrawContainer(), ContainerContainer::GetInstance().GetMoveContainer(), ContainerContainer::GetInstance().GetCollideContainer());
	b->SetDrawBehaviour("NormalBulletDrawBehaviour");
	b->SetCollideBehaviour("NormalBulletCollideBehaviour");
}


