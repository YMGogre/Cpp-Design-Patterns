#ifndef STRATEGY_H
#define STRATEGY_H

/// <summary>
/// 抽象类 Strategy
/// </summary>
class Strategy
{

public:
	/// <summary>
	/// 纯虚执行操作函数
	/// </summary>
	/// <param name="num1">操作数一</param>
	/// <param name="num2">操作数二</param>
	/// <returns>操作后的结果</returns>
	virtual int doOperation(int num1, int num2) = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Strategy() {}
};

#endif // !STRATEGY_H