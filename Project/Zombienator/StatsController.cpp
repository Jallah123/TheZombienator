#include "StatsController.h"

StatsController::StatsController() {}
StatsController::~StatsController() {}

std::string StatsController::GetTotalTime()
{
	int sec = int((float(clock() - this->startTime) / CLOCKS_PER_SEC) + 0.5f);

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
	this->kills = 0;
	this->totalKills = 0;
	this->totalBullets = 0;
	this->totalWavesDefeated = 0;
	this->startTime = clock();
}
