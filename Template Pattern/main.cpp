#include "Game.h"
#include "Cricket.h"
#include "Football.h"
#include <iostream>

int main() {
	Game* game = new Cricket();
	game->play();
	delete game;

	std::cout << std::endl;

	Football football;
	Game& game2 = football;
	game2.play();
}