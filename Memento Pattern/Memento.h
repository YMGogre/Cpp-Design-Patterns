#ifndef MEMENTO_H
#define MEMENTO_H

#include <string>

/// <summary>
/// ����¼��
/// </summary>
class Memento 
{
	
private:
	/// <summary>Ҫ���ָ��Ķ����״̬</summary>
	std::string state;

public:
	Memento(std::string _state) : state(_state) {}
	inline std::string getState() {
		return state;
	}
};

#endif // !MEMENTO_H