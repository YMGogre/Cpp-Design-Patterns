#ifndef PACKING_H
#define PACKING_H

#include <string>

/// <summary>
/// 表示食物包装的抽象类 Packing
/// </summary>
class Packing {

public:
	/// <summary>
	/// 纯虚包装函数
	/// </summary>
	/// <returns>表征包装的字符串</returns>
	virtual std::string pack() = 0;
	virtual ~Packing() {}
};

#endif // !PACKING_H