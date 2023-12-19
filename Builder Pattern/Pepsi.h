#ifndef PEPSI_H
#define PEPSI_H

#include "ColdDrink.h"

/// <summary>
/// 实现抽象类 ColdDrink 的实体类 Pepsi
/// </summary>
class Pepsi :
	public ColdDrink
{

public:
	/// <summary>
	/// 实现基类的纯虚名称函数
	/// </summary>
	/// <returns>返回食物的名称字符串</returns>
	inline virtual std::string name() override {
		return "Pepsi";
	}
	/// <summary>
	/// 实现基类的纯虚价格函数
	/// </summary>
	/// <returns>返回食物的价格</returns>
	inline virtual float price() override {
		return 35.0f;
	}
};

#endif // !PEPSI_H