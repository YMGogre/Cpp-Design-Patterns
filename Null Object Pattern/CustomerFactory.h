#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "AbstractCustomer.h"
#include "RealCustomer.h"
#include "NullCustomer.h"
#include <string>
#include <algorithm>

/// <summary>
/// 工厂类 CustomerFactory
/// </summary>
class CustomerFactory
{
public:
	static const std::string names[3];
	/// <summary>
	/// 获取客户对象
	/// </summary>
	/// <param name="name">客户名字</param>
	/// <returns>返回 RealCustomer 对象指针如果 names 中包含指定的客户名字；否则返回 NullCustomer 对象指针</returns>
	static inline AbstractCustomer* getCustomer(std::string name) {
		if (std::find(std::begin(names), std::end(names), name) != std::end(names)) {
			return new RealCustomer(name);
		}
		return new NullCustomer();
	}
};

#endif // !CUSTOMERFACTORY_H