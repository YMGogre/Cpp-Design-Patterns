#ifndef NULLCUSTOMER_H
#define NULLCUSTOMER_H

#include "AbstractCustomer.h"
#include <string>

/// <summary>
/// ʵ�ֳ����� AbstractCustomer ��ʵ���� NullCustomer
/// </summary>
class NullCustomer :
	public AbstractCustomer
{

public:
	NullCustomer() : AbstractCustomer("") {}
	/// <summary>
	/// ʵ�ֻ���Ĵ����ȡ�ͻ������ֺ���
	/// </summary>
	/// <returns>�ͻ�����</returns>
	inline virtual std::string getName() override {
		return "Not Available in Customer Database";
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ͻ��Ƿ�Ϊ�պ���
	/// </summary>
	/// <returns>���� true ���Ϊ�գ����򷵻� false</returns>
	inline virtual bool isNil() override {
		return true;
	}
};

#endif // !NULLCUSTOMER_H