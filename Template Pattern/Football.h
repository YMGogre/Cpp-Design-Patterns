#ifndef FOOTBALL_H
#define FOOTBALL_H

#include "Game.h"
#include <iostream>

/// <summary>
/// 实现抽象类 Game 的足球游戏类 Football
/// </summary>
class Football :
	public Game
{

protected:
	inline virtual void endPlay() override {
		std::cout << "Football Game Finished!" << std::endl;
	}
	inline virtual void initialize() override {
		std::cout << "Football Game Initialized! Start playing." << std::endl;
	}
	inline virtual void startPlay() override {
		std::cout << "Football Game Started. Enjoy the game!" << std::endl;
	}
};

#endif // !FOOTBALL_H