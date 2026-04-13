#pragma once

class Score {
public:
	Score();

	void reset();
	void addPoint(int amount = 1);
	int getCurrentScore() const;

private:
	int currentScore_;
};

