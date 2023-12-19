#ifndef COKE_H
#define COKE_H

#include "ColdDrink.h"

/// <summary>
/// ʵ�ֳ����� ColdDrink ��ʵ���� Coke
/// </summary>
class Coke :
	public ColdDrink
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ������ƺ���
	/// </summary>
	/// <returns>����ʳ��������ַ���</returns>
	inline virtual std::string name() override {
		return "Coke";
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���۸���
	/// </summary>
	/// <returns>����ʳ��ļ۸�</returns>
	inline virtual float price() override {
		return 30.0f;
	}
};

#endif // !COKE_H