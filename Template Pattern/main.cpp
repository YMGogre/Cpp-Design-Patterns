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
	football.play();
	// 对 play() 函数的调用其实也不需要多态特性，因为它一定调用的是 Game 类的 play() 函数
	//Game& game2 = football;
	//game2.play();
}