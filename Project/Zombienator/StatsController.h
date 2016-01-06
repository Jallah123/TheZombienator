#pragma once
#include <string>
#include <ctime>

class StatsController
{
	private:
		StatsController();
		int kills = 0;
		int totalKills = 0;
		int totalBullets = 0;
		int totalWavesDefeated = 0;
		long startTime;
	public:
		~StatsController();

		static StatsController* GetInstance() { //Singleton
			static StatsController f;
			return &f;
		}

		void AddKill() { this->kills++; this->totalKills++; };
		void AddBullet() { this->totalBullets++; };
		void AddWaveDefeated() { this->totalWavesDefeated++; };

		int GetKills() { return this->kills; }
		int GetTotalKills() { return this->totalKills; };
		int GetTotalBullets() { return this->totalBullets; }
		int GetTotalWavesDefeated() { return this->totalWavesDefeated; };
		std::string GetTotalTime();

		void SetKills(int _kills) { this->kills = _kills; };
	
		void Reset();
};

