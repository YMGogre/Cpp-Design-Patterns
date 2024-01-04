#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include <string>
#include "Memento.h"

/// <summary>
/// 原发器类 Originator，负责创建状态并在 Memento 对象中存储状态
/// </summary>
class Originator 
{
	
private:
	std::string state;

public:
	inline void setState(std::string _state) {
		state = _state;
	}
	inline std::string getState() {
		return state;
	}
	inline Memento saveStateToMemento() {
		return Memento(state);
	}
	inline void getStateFromMemento(Memento memento) {
		state = memento.getState();
	}
};

#endif // !ORIGINATOR_H