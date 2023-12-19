#ifndef CONTEXT_H
#define CONTEXT_H

//#include "State.h"

class State;	// 使用前向声明以避免循环依赖

/// <summary>
/// 带有某个状态的类
/// </summary>
class Context
{
	
private:
	State* state = nullptr;

public:
	// <https://stackoverflow.com/questions/6502828/what-does-default-mean-after-a-class-function-declaration>
	Context() = default;	
	Context(State* _state) : state(_state) {}
	inline void setState(State* _state) {
		state = _state;
	}
	inline State* getState() {
		return state;
	}
};

#endif // !CONTEXT_H