#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include "Order.h"

class Broker
{

private:
	std::vector<Order*> orderList;

public:
	/// <summary>
	/// 接受订单，该方法将新的订单命令加入到命令列表
	/// </summary>
	/// <param name="order">命令对象的指针</param>
	inline void takeOrder(Order* order) {
		orderList.push_back(order);
	}
	/// <summary>
	/// 下订单，该方法将会执行命令列表中的所有命令
	/// </summary>
	inline void placeOrders() {
		for (Order* order : orderList) {
			order->execute();
		}
		orderList.clear();
	}
};

#endif // !BROKER_H