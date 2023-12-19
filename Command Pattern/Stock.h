#ifndef STOCK_H
#define STOCK_H

#include <iostream>

/// <summary>
/// 作为请求的 Stock 库存类，包含购买和出售库存两个请求
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
	/// 购买库存
	/// </summary>
	inline void buy() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought" << std::endl;
	}
	/// <summary>
	/// 出售库存
	/// </summary>
	inline void sell() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
	}
};

#endif // !STOCK_H