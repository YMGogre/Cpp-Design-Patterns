#ifndef ORDER_H
#define ORDER_H

/// <summary>
/// ��������� Order
/// </summary>
class Order
{

public:
	/// <summary>
	/// ����ִ�������
	/// </summary>
	virtual void execute() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Order() {}
};

#endif // !ORDER_H