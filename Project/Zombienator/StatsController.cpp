#include "StatsController.h"

int StatsController::kills = 0;
int StatsController::totalKills = 0;
int StatsController::totalBullets = 0;
int StatsController::totalWavesDefeated = 0;
long StatsController::startTime = clock();

StatsController::StatsController() {}
StatsController::~StatsController() {}

std::string StatsController::GetTotalTime()
{
	int sec = int((float(clock() - startTime) / CLOCKS_PER_SEC) + 0.5f);

	int hours = sec / 60 / 60;
	int minutes = (sec / 60) % 60;
	int seconds = sec % 60;

	std::string h = std::to_string(hours);
	std::string m = std::to_string(minutes);
	std::string s = std::to_string(seconds);

	if (h.size() == 1) h = "0" + h;
	if (m.size() == 1) m = "0" + m;
	if (s.size() == 1) s = "0" + s;

	return h + ":" + m + ":" + s;
}

void StatsController::Reset()
{
	kills = 0;
	totalKills = 0;
	totalBullets = 0;
	totalWavesDefeated = 0;
	startTime = clock();
}
