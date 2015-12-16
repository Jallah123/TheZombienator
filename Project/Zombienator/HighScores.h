#pragma once
#include "ioController.h"
#include <cereal/types/map.hpp>
#include <cereal/types/list.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/complex.hpp>

// for doing the actual serialization
#include <cereal/archives/json.hpp>
#include <iostream>
#include <fstream>

#include <algorithm>
using namespace std;
class HighScores
{
private:
	

	void SortHighScores();
	void DeleteLowest();
	int GetLowest();
	std::list<int> highScores;
	

	friend class cereal::access;
	template <class Archive>
	void serialize(Archive & ar)
	{
		ar(CEREAL_NVP(highScores));
	}

	ioController* ioC = &ioController::GetInstance();

public:
	HighScores();
	~HighScores();
	void Save();
	void Insert(int newScore);
	list<int> GetHighScores() { return highScores; };

};

