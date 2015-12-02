#include "StatsController.h"


int StatsController::kills = 0;
int StatsController::totalKills = 0;
int StatsController::totalWavesDefeated = 0;
StatsController::StatsController()
{
}


StatsController::~StatsController()
{
}

void StatsController::AddKill()
{
	kills++;
	totalKills++;
}

void StatsController::AddWaveDefeated()
{
	totalWavesDefeated++;
}

int StatsController::GetKills()
{
	return kills;
}


int StatsController::GetTotalKills()
{
	return totalKills;
}

int StatsController::GetTotalWavesDefeated()
{
	return totalWavesDefeated;
}
