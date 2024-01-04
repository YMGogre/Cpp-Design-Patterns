#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include <string>
#include "Memento.h"

/// <summary>
/// ԭ������ Originator�����𴴽�״̬���� Memento �����д洢״̬
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