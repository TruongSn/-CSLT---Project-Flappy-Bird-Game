#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "../core/GameState.hpp"

class UI {
public:
	bool initialize(const std::string& fontPath);
	void render(sf::RenderWindow& window,
					GameState state,
					int currentScore,
					int bestScore,
					int lastScore) const;

private:
	void drawCenteredText(sf::RenderWindow& window,
						  const std::string& message,
						  unsigned int characterSize,
						  float y,
						  sf::Color color) const;

	sf::Font font_;
	bool hasFont_ = false;
};

