#ifndef ANDEXPRESSION_H
#define ANDEXPRESSION_H

#include "Expression.h"
#include <string>
#include <memory>

/// <summary>
/// ʵ�ֳ����� Expression ����Ͻ������� AndExpression�����ڴ������ʽ���ʽ
/// </summary>
class AndExpression :
	public Expression
{

private:
	std::shared_ptr<Expression> expr1;
	std::shared_ptr<Expression> expr2;

public:
	inline AndExpression(std::shared_ptr<Expression> _expr1, std::shared_ptr<Expression> _expr2) :
		expr1(_expr1), expr2(_expr2) {}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ͺ���
	/// </summary>
	/// <param name="context">�����͵�������</param>
	/// <returns>�Ƿ���ͳɹ�</returns>
	inline virtual bool interpret(std::string context) override {
		return expr1->interpret(context) && expr2->interpret(context);
	}
};

#endif // !ANDEXPRESSION_H