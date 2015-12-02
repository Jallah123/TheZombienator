#pragma once
class StatsController
{
private:
	StatsController();
	static int kills;
	static int totalKills;
	static int totalWavesDefeated;
public:
	~StatsController();
	static StatsController* Instance() {//Singleton
		static StatsController f;
		return &f;
	}
	static void AddKill();
	static void AddWaveDefeated();
	static int GetKills();
	static int GetTotalKills();
	static int GetTotalWavesDefeated();
	static void SetKills(int _kills) { kills = _kills; };
};

