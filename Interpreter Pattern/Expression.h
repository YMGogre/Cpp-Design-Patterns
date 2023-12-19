#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

/// <summary>
/// ���ʽ������ Expression
/// </summary>
class Expression
{

public:
	/// <summary>
	/// ������ͺ���
	/// </summary>
	/// <param name="context">�����͵�������</param>
	/// <returns>�Ƿ���ͳɹ�</returns>
	virtual bool interpret(std::string context) = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Expression() {}
};

#endif // !EXPRESSION_H