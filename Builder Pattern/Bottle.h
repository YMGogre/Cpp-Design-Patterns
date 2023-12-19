#ifndef BOTTLE_H
#define BOTTLE_H

#include "Packing.h"

/// <summary>
/// 实现抽象类 Packing 的实体类 Bottle
/// </summary>
class Bottle :
	public Packing
{

public:
	/// <summary>
	/// 实现基类的纯虚包装函数
	/// </summary>
	/// <returns>表征包装的字符串</returns>
	inline virtual std::string pack() override {
		return "Bottle";
	}
};

#endif // !BOTTLE_H