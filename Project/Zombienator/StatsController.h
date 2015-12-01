#pragma once
class StatsController
{
private:
	StatsController();
	static int kills;
public:
	~StatsController();
	static StatsController* Instance() {//Singleton
		static StatsController f;
		return &f;
	}
	static void AddKill();
	static int GetKills();
	static void SetKills(int _kills) { kills = _kills; };
};

