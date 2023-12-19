#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

/// <summary>
/// 表达式抽象类 Expression
/// </summary>
class Expression
{

public:
	/// <summary>
	/// 纯虚解释函数
	/// </summary>
	/// <param name="context">待解释的上下文</param>
	/// <returns>是否解释成功</returns>
	virtual bool interpret(std::string context) = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Expression() {}
};

#endif // !EXPRESSION_H