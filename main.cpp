#include "src/core/Game.hpp"

#include <exception>
#include <iostream>

int main() {
	try {
		Game game;
		game.run();
		return 0;
	} catch (const std::exception& ex) {
		std::cerr << "Failed to start game: " << ex.what() << '\n';
		return 1;
	}
}
