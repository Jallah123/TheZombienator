#pragma once
#include "CollideBehaviour.h"

class NormalBulletCollideBehaviour :
	public CollideBehaviour
{
public:
	NormalBulletCollideBehaviour() {};
	~NormalBulletCollideBehaviour();
	virtual void Collide(float dt) override;
	GameObject* GetClosest(std::vector<GameObject*> objects, GameObject& origin);
};

