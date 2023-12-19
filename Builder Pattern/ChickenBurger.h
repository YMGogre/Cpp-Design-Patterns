#ifndef CHICKENBURGER_H
#define CHICKENBURGER_H

#include "Burger.h"

/// <summary>
/// ʵ�ֳ����� Burger ��ʵ���� ChickenBurger
/// </summary>
class ChickenBurger :
	public Burger
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ������ƺ���
	/// </summary>
	/// <returns>����ʳ��������ַ���</returns>
	inline virtual std::string name() override {
		return "Chicken Burger";
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���۸���
	/// </summary>
	/// <returns>����ʳ��ļ۸�</returns>
	inline virtual float price() override {
		return 50.5f;
	}
};

#endif // !CHICKENBURGER_H