#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "Expression.h"
#include <string>

/// <summary>
/// 实现抽象类 Expression 的主要解释器类 TerminalExpression
/// </summary>
class TerminalExpression :
	public Expression
{

private:
	/// <summary>当前表达式的数据</summary>
	std::string data;

public:
	inline TerminalExpression(std::string _data) : data(_data) {}
	/// <summary>
	/// 实现基类的纯虚解释函数
	/// </summary>
	/// <param name="context">待解释的上下文</param>
	/// <returns>是否解释成功</returns>
	inline virtual bool interpret(std::string context) override {
		if (context.find(data) != std::string::npos) {
			return true;	// 如果传入的上下文中包含当前表达式，则认为可以解释当前上下文，返回 true
		}
		return false;
	}
};

#endif // !TERMINALEXPRESSION_H