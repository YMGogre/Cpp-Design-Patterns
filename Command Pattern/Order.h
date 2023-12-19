#ifndef ORDER_H
#define ORDER_H

/// <summary>
/// 命令抽象类 Order
/// </summary>
class Order
{

public:
	/// <summary>
	/// 纯虚执行命令函数
	/// </summary>
	virtual void execute() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Order() {}
};

#endif // !ORDER_H