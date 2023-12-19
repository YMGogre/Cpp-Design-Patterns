#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

/// <summary>
/// 备忘录类
/// </summary>
class Memento 
{
	
private:
	/// <summary>要被恢复的对象的状态</summary>
	std::string state;

public:
	Memento(std::string _state) : state(_state) {}
	inline std::string getState() {
		return state;
	}
};

#endif // !MEMENTO_H