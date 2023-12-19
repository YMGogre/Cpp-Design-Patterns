#ifndef COKE_H
#define COKE_H

#include "ColdDrink.h"

/// <summary>
/// 实现抽象类 ColdDrink 的实体类 Coke
/// </summary>
class Coke :
	public ColdDrink
{

public:
	/// <summary>
	/// 实现基类的纯虚名称函数
	/// </summary>
	/// <returns>返回食物的名称字符串</returns>
	inline virtual std::string name() override {
		return "Coke";
	}
	/// <summary>
	/// 实现基类的纯虚价格函数
	/// </summary>
	/// <returns>返回食物的价格</returns>
	inline virtual float price() override {
		return 30.0f;
	}
};

#endif // !COKE_H