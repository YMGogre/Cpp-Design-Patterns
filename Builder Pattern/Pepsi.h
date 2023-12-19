#ifndef PEPSI_H
#define PEPSI_H

#include "ColdDrink.h"

/// <summary>
/// ʵ�ֳ����� ColdDrink ��ʵ���� Pepsi
/// </summary>
class Pepsi :
	public ColdDrink
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ������ƺ���
	/// </summary>
	/// <returns>����ʳ��������ַ���</returns>
	inline virtual std::string name() override {
		return "Pepsi";
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���۸���
	/// </summary>
	/// <returns>����ʳ��ļ۸�</returns>
	inline virtual float price() override {
		return 35.0f;
	}
};

#endif // !PEPSI_H