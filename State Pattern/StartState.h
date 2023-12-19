#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "State.h"
#include "Context.h"
#include <string>
#include <iostream>

/// <summary>
/// 实现抽象类 State 的实体类 StartState
/// </summary>
class StartState :
	public State
{

public:
	/// <summary>
	/// 实现基类的纯虚执行动作函数
	/// </summary>
	/// <param name="context">带有某个状态的类</param>
	inline virtual void doAction(Context& context) override {
		std::cout << "Player is in start state" << std::endl;
		context.setState(this);
	}
	/// <summary>
	/// 实现基类的纯虚转字符串函数
	/// </summary>
	/// <returns>转换后的字符串</returns>
	inline virtual std::string toString() override {
		return "Start State";
	}
};

#endif // !STARTSTATE_H