#pragma once

#include <SFML/Graphics.hpp>

#include "../systems/Score.hpp"
#include "../ui/UI.hpp"
#include "GameState.hpp"

class Game {
public:
	Game();
	void run();

private:
	void processInput();
	void update(float deltaTime);
	void render();
	void resetGame();
	void setState(GameState nextState);

	sf::RenderWindow window_;
	GameState currentState_;
	UI ui_;
	Score score_;
};

