#ifndef ITEM_H
#define ITEM_H

#include "Packing.h"

/// <summary>
/// 表示食物条目的抽象类 Item
/// </summary>
class Item {

public:
	/// <summary>
	/// 纯虚名称函数
	/// </summary>
	/// <returns>返回食物的名称字符串</returns>
	virtual std::string name() = 0;
	/// <summary>
	/// 纯虚包装函数
	/// </summary>
	/// <returns>返回表示食物包装的抽象类 Packing 的指针</returns>
	virtual Packing* packing() = 0;
	/// <summary>
	/// 纯虚价格函数
	/// </summary>
	/// <returns>返回食物的价格</returns>
	virtual float price() = 0;
	virtual ~Item() {}
};

#endif // !ITEM_H