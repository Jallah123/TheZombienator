#pragma once
#include <string>
#include <ctime>

class StatsController
{
	private:
		StatsController();
		static int kills;
		static int totalKills;
		static int totalBullets;
		static int totalWavesDefeated;
		static long startTime;
	public:
		~StatsController();

		static StatsController* GetInstance() { //Singleton
			static StatsController f;
			return &f;
		}

		static void AddKill() { kills++; totalKills++; };
		static void AddBullet() { totalBullets++; };
		static void AddWaveDefeated() { totalWavesDefeated++; };

		static int GetKills() { return kills; }
		static int GetTotalKills() { return totalKills; };
		static int GetTotalBullets() { return totalBullets; }
		static int GetTotalWavesDefeated() { return totalWavesDefeated; };
		static void StartTime() { startTime = clock(); }
		static std::string GetTotalTime();

		static void SetKills(int _kills) { kills = _kills; };
	
		static void Reset();
};

