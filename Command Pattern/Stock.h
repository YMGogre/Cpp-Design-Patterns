#ifndef STOCK_H
#define STOCK_H

#include <iostream>

/// <summary>
/// 作为接收者的 Stock 股票类，其知道如何执行与请求相关的操作
/// </summary>
class Stock
{

private:
	/// <summary>名称</summary>
	const char* name = "ABC";
	/// <summary>数量</summary>
	int quantity = 10;

public:
	/// <summary>
	/// 购买股票
	/// </summary>
	inline void buy() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought" << std::endl;
	}
	/// <summary>
	/// 卖出股票
	/// </summary>
	inline void sell() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
	}
};

#endif // !STOCK_H