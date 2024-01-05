#ifndef BROKER_H
#define BROKER_H

#include <vector>
#include "Order.h"

/// <summary>
/// ������ Broker����������������ִ������
/// </summary>
class Broker
{

private:
	std::vector<Order*> orderList;

public:
	/// <summary>
	/// ��������÷������µ�������뵽�����б�
	/// </summary>
	/// <param name="order">��������ָ��</param>
	inline void takeOrder(Order* order) {
		orderList.push_back(order);
	}
	/// <summary>
	/// �÷�������ִ�������б��е���������
	/// </summary>
	inline void placeOrders() {
		for (Order* order : orderList) {
			order->execute();
		}
		orderList.clear();
	}
};

#endif // !BROKER_H