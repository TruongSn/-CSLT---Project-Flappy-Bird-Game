#include "UI.hpp"

#include <string>

bool UI::initialize(const std::string& fontPath) {
	hasFont_ = font_.loadFromFile(fontPath);
	return hasFont_;
}

void UI::drawCenteredText(sf::RenderWindow& window,
						  const std::string& message,
						  unsigned int characterSize,
						  float y,
						  sf::Color color) const {
	if (!hasFont_) {
		return;
	}

	sf::Text text;
	text.setFont(font_);
	text.setString(message);
	text.setCharacterSize(characterSize);
	text.setFillColor(color);

	const sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(bounds.left + bounds.width * 0.5f, bounds.top + bounds.height * 0.5f);
	text.setPosition(static_cast<float>(window.getSize().x) * 0.5f, y);

	window.draw(text);
}

void UI::render(sf::RenderWindow& window, GameState state, int currentScore) const {
	if (!hasFont_) {
		return;
	}

	switch (state) {
		case GameState::Start:
			drawCenteredText(window, "FLAPPY BIRD", 48U, 180.0f, sf::Color::White);
			drawCenteredText(window, "Week 1 Scaffold Ready", 28U, 250.0f, sf::Color(210, 220, 240));
			drawCenteredText(window, "Press ENTER / SPACE / Click to start", 22U, 380.0f, sf::Color(235, 235, 235));
			drawCenteredText(window, "Press ESC to pause when playing", 18U, 430.0f, sf::Color(185, 200, 215));
			break;

		case GameState::Playing: {
			sf::Text scoreText;
			scoreText.setFont(font_);
			scoreText.setCharacterSize(34U);
			scoreText.setFillColor(sf::Color::White);
			scoreText.setString("Score: " + std::to_string(currentScore));
			scoreText.setPosition(20.0f, 18.0f);
			window.draw(scoreText);

			drawCenteredText(window, "Core loop is running", 20U, 70.0f, sf::Color(205, 215, 235));
			drawCenteredText(window, "Press G to simulate Game Over", 18U, 105.0f, sf::Color(185, 200, 215));
			break;
		}

		case GameState::Paused:
			drawCenteredText(window, "PAUSED", 48U, 220.0f, sf::Color::White);
			drawCenteredText(window, "Press ESC to continue", 24U, 300.0f, sf::Color(220, 230, 245));
			break;

		case GameState::GameOver:
			drawCenteredText(window, "GAME OVER", 48U, 200.0f, sf::Color::White);
			drawCenteredText(window, "Final Score: " + std::to_string(currentScore), 30U, 280.0f, sf::Color(240, 245, 255));
			drawCenteredText(window, "Press ENTER / SPACE / Click to play again", 22U, 360.0f, sf::Color(215, 225, 240));
			break;
	}
}
