#ifndef OREXPRESSION_H
#define OREXPRESSION_H

#include "Expression.h"
#include <string>
#include <memory>

/// <summary>
/// ʵ�ֳ����� Expression ����Ͻ������� OrExpression�����ڴ������ʽ���ʽ
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
	/// ʵ�ֻ���Ĵ�����ͺ���
	/// </summary>
	/// <param name="context">�����͵�������</param>
	/// <returns>�Ƿ���ͳɹ�</returns>
	inline virtual bool interpret(std::string context) override {
		return expr1->interpret(context) || expr2->interpret(context);
	}
};

#endif // !OREXPRESSION_H