#ifndef BURGER_H
#define BURGER_H

#include "Item.h"
#include "Wrapper.h"

/// <summary>
/// 部分实现抽象类 Item 的抽象类 Burger
/// </summary>
class Burger :
	public Item
{

public:
	/// <summary>
	/// 实现基类的纯虚包装函数
	/// </summary>
	/// <returns>返回表示食物包装的抽象类 Packing 的指针</returns>
	inline virtual Packing* packing() override {
		return new Wrapper();
	}
};

#endif // !BURGER_H