#ifndef OREXPRESSION_H
#define OREXPRESSION_H

#include "Expression.h"
#include <string>
#include <memory>

/// <summary>
/// 实现抽象类 Expression 的组合解释器类 OrExpression，用于创建组合式表达式
/// </summary>
class OrExpression :
	public Expression
{

private:
	std::shared_ptr<Expression> expr1;
	std::shared_ptr<Expression> expr2;

public:
	inline OrExpression(std::shared_ptr<Expression> _expr1, std::shared_ptr<Expression> _expr2) :
		expr1(_expr1), expr2(_expr2) {}
	/// <summary>
	/// 实现基类的纯虚解释函数
	/// </summary>
	/// <param name="context">待解释的上下文</param>
	/// <returns>是否解释成功</returns>
	inline virtual bool interpret(std::string context) override {
		return expr1->interpret(context) || expr2->interpret(context);
	}
};

#endif // !OREXPRESSION_H