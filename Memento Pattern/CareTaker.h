#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include "Memento.h"

/// <summary>
/// 备忘录管理者类 CareTaker，负责管理 Memento 对象
/// </summary>
class CareTaker
{

private:
	std::vector<Memento> mementoList;

public:
	inline void add(Memento state) {
		mementoList.push_back(state);
	}
	inline Memento get(int index) {
		return mementoList[index];
	}
};

#endif // !CARETAKER_H