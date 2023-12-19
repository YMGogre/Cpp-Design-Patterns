#ifndef NULLCUSTOMER_H
#define NULLCUSTOMER_H

#include "AbstractCustomer.h"
#include <string>

/// <summary>
/// 实现抽象类 AbstractCustomer 的实体类 NullCustomer
/// </summary>
class NullCustomer :
	public AbstractCustomer
{

public:
	NullCustomer() : AbstractCustomer("") {}
	/// <summary>
	/// 实现基类的纯虚获取客户的名字函数
	/// </summary>
	/// <returns>客户名字</returns>
	inline virtual std::string getName() override {
		return "Not Available in Customer Database";
	}
	/// <summary>
	/// 实现基类的纯虚检查客户是否为空函数
	/// </summary>
	/// <returns>返回 true 如果为空，否则返回 false</returns>
	inline virtual bool isNil() override {
		return true;
	}
};

#endif // !NULLCUSTOMER_H