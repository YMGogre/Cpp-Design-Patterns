#ifndef STRATEGY_H
#define STRATEGY_H

/// <summary>
/// ������ Strategy
/// </summary>
class Strategy
{

public:
	/// <summary>
	/// ����ִ�в�������
	/// </summary>
	/// <param name="num1">������һ</param>
	/// <param name="num2">��������</param>
	/// <returns>������Ľ��</returns>
	virtual int doOperation(int num1, int num2) = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Strategy() {}
};

#endif // !STRATEGY_H