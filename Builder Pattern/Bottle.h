#ifndef BOTTLE_H
#define BOTTLE_H

#include "Packing.h"

/// <summary>
/// ʵ�ֳ����� Packing ��ʵ���� Bottle
/// </summary>
class Bottle :
	public Packing
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ����װ����
	/// </summary>
	/// <returns>������װ���ַ���</returns>
	inline virtual std::string pack() override {
		return "Bottle";
	}
};

#endif // !BOTTLE_H