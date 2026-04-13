#include "Game.hpp"

#include <array>

namespace {
constexpr unsigned int kWindowWidth = 480U;
constexpr unsigned int kWindowHeight = 720U;
constexpr unsigned int kTargetFps = 60U;
}  // namespace

Game::Game()
	: window_(sf::VideoMode(kWindowWidth, kWindowHeight),
			  "Flappy Bird - Week 1",
			  sf::Style::Titlebar | sf::Style::Close),
	  currentState_(GameState::Start),
	  ui_(),
	  score_() {
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

	(void)deltaTime;
}

void Game::render() {
	window_.clear(sf::Color(32, 41, 57));
	ui_.render(window_, currentState_, score_.getCurrentScore());
	window_.display();
}

void Game::resetGame() {
	score_.reset();
}

void Game::setState(GameState nextState) {
	currentState_ = nextState;
}
