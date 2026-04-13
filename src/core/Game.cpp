#include "Game.hpp"

#include <array>

#include "../config/GameplayConfig.hpp"

namespace {
constexpr unsigned int kTargetFps = 60U;
}  // namespace

Game::Game()
	: window_(sf::VideoMode(GameplayConfig::WindowWidth, GameplayConfig::WindowHeight),
			  GameplayConfig::WindowTitle,
			  sf::Style::Titlebar | sf::Style::Close),
	  currentState_(GameState::Start),
	  ui_(),
	  score_(),
	  bird_(),
	  groundY_(static_cast<float>(GameplayConfig::WindowHeight) - GameplayConfig::GroundHeight) {
	window_.setFramerateLimit(kTargetFps);

	const std::array<std::string, 3> fontCandidates = {
		"assets/fonts/font_flappy.ttf",
		"../assets/fonts/font_flappy.ttf",
		"../../assets/fonts/font_flappy.ttf",
	};

	for (const std::string& path : fontCandidates) {
		if (ui_.initialize(path)) {
			break;
		}
	}
}

void Game::run() {
	sf::Clock frameClock;

	while (window_.isOpen()) {
		const float deltaTime = frameClock.restart().asSeconds();
		processInput();
		update(deltaTime);
		render();
	}
}

void Game::processInput() {
	sf::Event event;

	while (window_.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window_.close();
			continue;
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (currentState_ == GameState::Start || currentState_ == GameState::GameOver) {
				resetGame();
				setState(GameState::Playing);
			} else if (currentState_ == GameState::Playing) {
				bird_.flap();
			}
			continue;
		}

		if (event.type != sf::Event::KeyPressed) {
			continue;
		}

		const sf::Keyboard::Key key = event.key.code;

		if (key == sf::Keyboard::Escape) {
			if (currentState_ == GameState::Playing) {
				setState(GameState::Paused);
			} else if (currentState_ == GameState::Paused) {
				setState(GameState::Playing);
			}
			continue;
		}

		if (key == sf::Keyboard::Enter || key == sf::Keyboard::Space) {
			if (currentState_ == GameState::Start || currentState_ == GameState::GameOver) {
				resetGame();
				setState(GameState::Playing);
			} else if (currentState_ == GameState::Playing && key == sf::Keyboard::Space) {
				bird_.flap();
			}
			continue;
		}

		if (key == sf::Keyboard::G && currentState_ == GameState::Playing) {
			setState(GameState::GameOver);
			continue;
		}
	}
}

void Game::update(float deltaTime) {
	if (currentState_ != GameState::Playing) {
		return;
	}

	bird_.update(deltaTime);

	const sf::FloatRect birdBounds = bird_.getBounds();
	if (birdBounds.top <= 0.0f || (birdBounds.top + birdBounds.height) >= groundY_) {
		setState(GameState::GameOver);
	}
}

void Game::render() {
	window_.clear(sf::Color(113, 197, 236));

	sf::RectangleShape ground(
		sf::Vector2f(static_cast<float>(window_.getSize().x), GameplayConfig::GroundHeight));
	ground.setPosition(0.0f, groundY_);
	ground.setFillColor(sf::Color(223, 200, 134));
	window_.draw(ground);

	bird_.render(window_);
	ui_.render(window_, currentState_, score_.getCurrentScore());
	window_.display();
}

void Game::resetGame() {
	score_.reset();
	bird_.reset();
}

void Game::setState(GameState nextState) {
	currentState_ = nextState;
}
