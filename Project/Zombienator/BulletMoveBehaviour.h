#pragma once
#include "MoveBehaviour.h"
class BulletMoveBehaviour :
	public MoveBehaviour
{
private:
	int speed = 5;
	float modifer = 1.6f;
public:
	BulletMoveBehaviour();
	~BulletMoveBehaviour();

	virtual void Move(float dt) override;
	void SetSpeed(int s) { speed = s; }
};

