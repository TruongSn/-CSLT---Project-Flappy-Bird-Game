#include "Score.hpp"

Score::Score() : currentScore_(0) {}

void Score::reset() {
	currentScore_ = 0;
}

void Score::addPoint(int amount) {
	if (amount <= 0) {
		return;
	}

	currentScore_ += amount;
}

int Score::getCurrentScore() const {
	return currentScore_;
}
