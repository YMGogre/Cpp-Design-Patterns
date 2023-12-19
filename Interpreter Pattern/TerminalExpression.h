#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "Expression.h"
#include <string>

/// <summary>
/// ʵ�ֳ����� Expression ����Ҫ�������� TerminalExpression
/// </summary>
class TerminalExpression :
	public Expression
{

private:
	/// <summary>��ǰ���ʽ������</summary>
	std::string data;

public:
	inline TerminalExpression(std::string _data) : data(_data) {}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ͺ���
	/// </summary>
	/// <param name="context">�����͵�������</param>
	/// <returns>�Ƿ���ͳɹ�</returns>
	inline virtual bool interpret(std::string context) override {
		if (context.find(data) != std::string::npos) {
			return true;	// ���������������а�����ǰ���ʽ������Ϊ���Խ��͵�ǰ�����ģ����� true
		}
		return false;
	}
};

#endif // !TERMINALEXPRESSION_H