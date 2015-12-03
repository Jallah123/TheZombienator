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
	static void Reset()
	{
		kills = 0;
	}
	static void AddKill();
	static int GetKills();
};

