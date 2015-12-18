#pragma once
#include "ActionBehaviour.h"
class SwitchWeapon2ActionBehaviour :
	public ActionBehaviour
{
private:
	bool isPressed = false;
	char actionBackward;
public:
	SwitchWeapon2ActionBehaviour();
	~SwitchWeapon2ActionBehaviour();

	virtual void Update(float dt) override;

};

