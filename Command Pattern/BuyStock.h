#ifndef BUYSTOCK_H
#define BUYSTOCK_H

#include "Order.h"
#include "Stock.h"

/// <summary>
/// 实现抽象类 Order 的实体命令类 BuyStock，将执行实际的购买库存命令处理
/// </summary>
class BuyStock :
	public Order
{

private:
	Stock abcStock;

public:
	BuyStock(Stock _abcStock) : abcStock(_abcStock) {}
	/// <summary>
	/// 实现基类的纯虚执行命令函数
	/// </summary>
	inline virtual void execute() {
		abcStock.buy();
	}
};

#endif // !BUYSTOCK_H