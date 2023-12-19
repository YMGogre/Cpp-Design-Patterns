#ifndef ABSTRACTCUSTOMER_H
#define ABSTRACTCUSTOMER_H

#include <string>

/// <summary>
/// 抽象客户类，可以操作客户的名字
/// </summary>
class AbstractCustomer
{

protected:
	/// <summary>客户的名字</summary>
	std::string name;

public:
	AbstractCustomer(std::string _name) : name(_name) {}
	/// <summary>
	/// 纯虚检查客户是否为空函数
	/// </summary>
	/// <returns>返回 true 如果为空，否则返回 false</returns>
	virtual bool isNil() = 0;
	/// <summary>
	/// 纯虚获取客户的名字函数
	/// </summary>
	/// <returns>客户名字</returns>
	virtual std::string getName() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~AbstractCustomer() {}
};

#endif // !ABSTRACTCUSTOMER_H