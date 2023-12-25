#ifndef CRICKET_H
#define CRICKET_H

#include "Game.h"
#include <iostream>

/// <summary>
/// ʵ�ֳ����� Game �İ�����Ϸ�� Cricket
/// </summary>
class Cricket :
	public Game
{

protected:
	inline virtual void endPlay() override {
		std::cout << "Cricket Game Finished!" << std::endl;
	}
	inline virtual void initialize() override {
		std::cout << "Cricket Game Initialized! Start playing." << std::endl;
	}
	inline virtual void startPlay() override {
		std::cout << "Cricket Game Started. Enjoy the game!" << std::endl;
	}
};

#endif // !CRICKET_H