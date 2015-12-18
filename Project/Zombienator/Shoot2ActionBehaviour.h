#pragma once
#include "ActionBehaviour.h"
class Shoot2ActionBehaviour :
	public ActionBehaviour
{
private:
	float elapsedTime = 0;
	float maxElapsed = 1000;
public:
	Shoot2ActionBehaviour();
	~Shoot2ActionBehaviour();

	virtual void Update(float dt) override;
};

