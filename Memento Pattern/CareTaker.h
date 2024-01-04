#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>
#include "Memento.h"

/// <summary>
/// ����¼�������� CareTaker��������� Memento ����
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