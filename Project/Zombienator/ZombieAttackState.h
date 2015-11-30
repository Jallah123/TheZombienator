#pragma once
#include "ZombieState.h"
#include <ctime>

class ZombieAttackState : public ZombieState
{
	private:
		clock_t soundBegin = clock();
		clock_t damageBegin = clock();

		float timeTillNewSound = 0;
		float timeTillNewDamage = 0;

		float GetPassedTime(clock_t t) { return float(clock() - t) / CLOCKS_PER_SEC; }
		
	public:
		ZombieAttackState();
		~ZombieAttackState();
		void CheckState();
		void Update(float dt);

		void PlaySound();
		void DoDamage();
};