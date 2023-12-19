#ifndef SELLSTOCK_H
#define SELLSTOCK_H

#include "Order.h"
#include "Stock.h"

/// <summary>
/// 实现抽象类 Order 的实体命令类 SellStock，将执行实际的出售库存命令处理
/// </summary>
class SellStock :
	public Order
{

private:
	Stock abcStock;

public:
	SellStock(Stock _abcStock) : abcStock(_abcStock) {}
	/// <summary>
	/// 实现基类的纯虚执行命令函数
	/// </summary>
	inline virtual void execute() {
		abcStock.sell();
	}
};

#endif // !SELLSTOCK_H