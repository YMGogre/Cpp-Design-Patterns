#ifndef STOCK_H
#define STOCK_H

#include <iostream>

/// <summary>
/// ��Ϊ����� Stock ����࣬��������ͳ��ۿ����������
/// </summary>
class Stock
{

private:
	/// <summary>����</summary>
	const char* name = "ABC";
	/// <summary>����</summary>
	int quantity = 10;

public:
	/// <summary>
	/// ������
	/// </summary>
	inline void buy() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] bought" << std::endl;
	}
	/// <summary>
	/// ���ۿ��
	/// </summary>
	inline void sell() {
		std::cout << "Stock [ Name: " << name << ", Quantity: " << quantity << " ] sold" << std::endl;
	}
};

#endif // !STOCK_H