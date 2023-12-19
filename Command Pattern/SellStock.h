#ifndef SELLSTOCK_H
#define SELLSTOCK_H

#include "Order.h"
#include "Stock.h"

/// <summary>
/// ʵ�ֳ����� Order ��ʵ�������� SellStock����ִ��ʵ�ʵĳ��ۿ�������
/// </summary>
class SellStock :
	public Order
{

private:
	Stock abcStock;

public:
	SellStock(Stock _abcStock) : abcStock(_abcStock) {}
	/// <summary>
	/// ʵ�ֻ���Ĵ���ִ�������
	/// </summary>
	inline virtual void execute() {
		abcStock.sell();
	}
};

#endif // !SELLSTOCK_H