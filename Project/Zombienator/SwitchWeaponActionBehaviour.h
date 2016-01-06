#pragma once
#include "ActionBehaviour.h"
class SwitchWeaponActionBehaviour :
	public ActionBehaviour
{
private:
	bool isPressed = false;
	char actionBackward;
public:
	SwitchWeaponActionBehaviour();
	~SwitchWeaponActionBehaviour();
	virtual void Init() override;
	virtual void Update(float dt) override;

};

