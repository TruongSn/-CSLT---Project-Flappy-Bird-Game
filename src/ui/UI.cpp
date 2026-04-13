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

void UI::render(sf::RenderWindow& window,
					GameState state,
					int currentScore,
					int bestScore,
					int lastScore) const {
	if (!hasFont_) {
		return;
	}

	auto drawHud = [&]() {
		sf::Text scoreText;
		scoreText.setFont(font_);
		scoreText.setCharacterSize(34U);
		scoreText.setFillColor(sf::Color::White);
		scoreText.setString("Score: " + std::to_string(currentScore));
		scoreText.setPosition(20.0f, 18.0f);
		window.draw(scoreText);

		sf::Text bestText;
		bestText.setFont(font_);
		bestText.setCharacterSize(22U);
		bestText.setFillColor(sf::Color(240, 245, 255));
		bestText.setString("Best: " + std::to_string(bestScore));

		const sf::FloatRect bestBounds = bestText.getLocalBounds();
		bestText.setPosition(static_cast<float>(window.getSize().x) - bestBounds.width - 26.0f, 24.0f);
		window.draw(bestText);
	};

	switch (state) {
		case GameState::Start:
			drawCenteredText(window, "FLAPPY BIRD", 48U, 180.0f, sf::Color::White);
			drawCenteredText(window, "Week 4 Score And Restart Flow", 28U, 250.0f, sf::Color(210, 220, 240));
			drawCenteredText(window, "Press ENTER / SPACE / Click to start", 22U, 380.0f, sf::Color(235, 235, 235));
			drawCenteredText(window, "SPACE / Click to flap, ESC to pause", 18U, 420.0f, sf::Color(185, 200, 215));
			if (bestScore > 0) {
				drawCenteredText(window, "Best Score: " + std::to_string(bestScore), 20U, 470.0f, sf::Color(230, 238, 252));
			}
			break;

		case GameState::Playing: {
			drawHud();
			drawCenteredText(window, "SPACE / Click: flap", 20U, 70.0f, sf::Color(205, 215, 235));
			drawCenteredText(window, "Avoid pipes, top and ground", 18U, 105.0f, sf::Color(185, 200, 215));
			break;
		}

		case GameState::Paused:
			drawHud();
			drawCenteredText(window, "PAUSED", 48U, 220.0f, sf::Color::White);
			drawCenteredText(window, "Press ESC to continue", 24U, 300.0f, sf::Color(220, 230, 245));
			drawCenteredText(window, "Press ENTER to restart", 20U, 350.0f, sf::Color(210, 223, 241));
			break;

		case GameState::GameOver: {
			sf::RectangleShape panel(
				sf::Vector2f(static_cast<float>(window.getSize().x) - 90.0f, 280.0f));
			panel.setPosition(45.0f, 170.0f);
			panel.setFillColor(sf::Color(18, 25, 38, 180));
			window.draw(panel);

			drawCenteredText(window, "GAME OVER", 48U, 200.0f, sf::Color::White);
			drawCenteredText(window, "Final Score: " + std::to_string(lastScore), 30U, 280.0f, sf::Color(240, 245, 255));
			drawCenteredText(window, "Best Score: " + std::to_string(bestScore), 24U, 325.0f, sf::Color(228, 236, 249));
			drawCenteredText(window, "Press ENTER / SPACE / Click or R to restart", 21U, 385.0f, sf::Color(215, 225, 240));
			break;
		}
			break;
	}
}
