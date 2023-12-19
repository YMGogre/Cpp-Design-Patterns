#ifndef VEGBURGER_H
#define VEGBURGER_H

#include "Burger.h"

/// <summary>
/// ʵ�ֳ����� Burger ��ʵ���� VegBurger
/// </summary>
class VegBurger :
	public Burger
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ������ƺ���
	/// </summary>
	/// <returns>����ʳ��������ַ���</returns>
	inline virtual std::string name() override {
		return "Veg Burger";
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���۸���
	/// </summary>
	/// <returns>����ʳ��ļ۸�</returns>
	inline virtual float price() override {
		return 25.0f;
	}
};

#endif // !VEGBURGER_H