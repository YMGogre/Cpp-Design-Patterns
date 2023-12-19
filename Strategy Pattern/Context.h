#ifndef CONTEXT_H
#define CONTEXT_H

#include "Strategy.h"

/// <summary>
/// Context ��һ��ʹ����ĳ�ֲ��Ե���
/// </summary>
class Context
{

private:
	Strategy* strategy;

public:
	Context(Strategy* _strategy) : strategy(_strategy) {}
	/// <summary>
	/// ʹ�� Context �����Ĳ���ִ�в���
	/// </summary>
	/// <param name="num1">������һ</param>
	/// <param name="num2">��������</param>
	/// <returns>������Ľ��</returns>
	inline int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
	~Context() {
		delete strategy;
	}
};

#endif // !CONTEXT_H