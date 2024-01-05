#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include "Order.h"

/// <summary>
/// 调用者 Broker，其根据命令对象来执行请求
/// </summary>
class Broker
{

private:
	std::vector<Order*> orderList;

public:
	/// <summary>
	/// 接受命令，该方法将新的命令加入到命令列表
	/// </summary>
	/// <param name="order">命令对象的指针</param>
	inline void takeOrder(Order* order) {
		orderList.push_back(order);
	}
	/// <summary>
	/// 该方法将会执行命令列表中的所有命令
	/// </summary>
	inline void placeOrders() {
		for (Order* order : orderList) {
			order->execute();
		}
		orderList.clear();
	}
};

#endif // !BROKER_H