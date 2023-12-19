#ifndef VEGBURGER_H
#define VEGBURGER_H

#include "Burger.h"

/// <summary>
/// 实现抽象类 Burger 的实体类 VegBurger
/// </summary>
class VegBurger :
	public Burger
{

public:
	/// <summary>
	/// 实现基类的纯虚名称函数
	/// </summary>
	/// <returns>返回食物的名称字符串</returns>
	inline virtual std::string name() override {
		return "Veg Burger";
	}
	/// <summary>
	/// 实现基类的纯虚价格函数
	/// </summary>
	/// <returns>返回食物的价格</returns>
	inline virtual float price() override {
		return 25.0f;
	}
};

#endif // !VEGBURGER_H