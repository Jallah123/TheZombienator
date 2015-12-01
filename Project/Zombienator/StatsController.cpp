#include "StatsController.h"


int StatsController::kills = 0;
StatsController::StatsController()
{
}


StatsController::~StatsController()
{
}

void StatsController::AddKill()
{
	kills++;
}

int StatsController::GetKills()
{
	return kills;
}