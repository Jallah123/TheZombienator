#include "HighScores.h"
HighScores::HighScores() {

}

HighScores::~HighScores() {

}

void HighScores::Save() {
	ioC->SafeFile("highscores", this);
}

void HighScores::Insert(int newScore) {
	if (highScores.size() < 10) {
		highScores.push_back(newScore);
		SortHighScores();
		return;
	}

	if (newScore >= GetLowest()) {
		if (highScores.size() >= 10) {
			DeleteLowest();
			highScores.push_back(newScore);
		}
		else {
			highScores.push_back(newScore);
		}
		SortHighScores();
	}
}

void HighScores::DeleteLowest() {
	highScores.remove(GetLowest());
}

int HighScores::GetLowest() {
	int lowest = highScores.front();
	for (auto& i : highScores) {
		if (i <= lowest) {
			lowest = i;
		}
	}

	return lowest;
}



void HighScores::SortHighScores() {
	highScores.sort(std::greater<int>());
}

