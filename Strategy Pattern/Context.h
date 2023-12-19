#ifndef CONTEXT_H
#define CONTEXT_H

#include "Strategy.h"

/// <summary>
/// Context 是一个使用了某种策略的类
/// </summary>
class Context
{

private:
	Strategy* strategy;

public:
	Context(Strategy* _strategy) : strategy(_strategy) {}
	/// <summary>
	/// 使用 Context 包含的策略执行操作
	/// </summary>
	/// <param name="num1">操作数一</param>
	/// <param name="num2">操作数二</param>
	/// <returns>操作后的结果</returns>
	inline int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
	~Context() {
		delete strategy;
	}
};

#endif // !CONTEXT_H