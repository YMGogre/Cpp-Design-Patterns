#ifndef REALCUSTOMER_H
#define REALCUSTOMER_H

#include "AbstractCustomer.h"
#include <string>

/// <summary>
/// ʵ�ֳ����� AbstractCustomer ��ʵ���� RealCustomer
/// </summary>
class RealCustomer :
	public AbstractCustomer
{

public:
	RealCustomer(std::string _name) : AbstractCustomer(_name) {}
	/// <summary>
	/// ʵ�ֻ���Ĵ����ȡ�ͻ������ֺ���
	/// </summary>
	/// <returns>�ͻ�����</returns>
	inline virtual std::string getName() override {
		return name;
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ͻ��Ƿ�Ϊ�պ���
	/// </summary>
	/// <returns>���� true ���Ϊ�գ����򷵻� false</returns>
	inline virtual bool isNil() override {
		return false;
	}
};

#endif // !REALCUSTOMER_H