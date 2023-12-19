#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H

#include "AbstractCustomer.h"
#include "RealCustomer.h"
#include "NullCustomer.h"
#include <string>
#include <algorithm>

/// <summary>
/// ������ CustomerFactory
/// </summary>
class CustomerFactory
{
public:
	static const std::string names[3];
	/// <summary>
	/// ��ȡ�ͻ�����
	/// </summary>
	/// <param name="name">�ͻ�����</param>
	/// <returns>���� RealCustomer ����ָ����� names �а���ָ���Ŀͻ����֣����򷵻� NullCustomer ����ָ��</returns>
	static inline AbstractCustomer* getCustomer(std::string name) {
		if (std::find(std::begin(names), std::end(names), name) != std::end(names)) {
			return new RealCustomer(name);
		}
		return new NullCustomer();
	}
};

#endif // !CUSTOMERFACTORY_H