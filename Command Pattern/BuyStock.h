#ifndef BUYSTOCK_H
#define BUYSTOCK_H

#include "Order.h"
#include "Stock.h"

/// <summary>
/// ʵ�ֳ����� Order ��ʵ�������� BuyStock����ִ��ʵ�ʵĹ����������
/// </summary>
class BuyStock :
	public Order
{

private:
	Stock abcStock;

public:
	BuyStock(Stock _abcStock) : abcStock(_abcStock) {}
	/// <summary>
	/// ʵ�ֻ���Ĵ���ִ�������
	/// </summary>
	inline virtual void execute() {
		abcStock.buy();
	}
};

#endif // !BUYSTOCK_H