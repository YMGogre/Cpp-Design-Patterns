#ifndef BURGER_H
#define BURGER_H

#include "Item.h"
#include "Wrapper.h"

/// <summary>
/// ����ʵ�ֳ����� Item �ĳ����� Burger
/// </summary>
class Burger :
	public Item
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ����װ����
	/// </summary>
	/// <returns>���ر�ʾʳ���װ�ĳ����� Packing ��ָ��</returns>
	inline virtual Packing* packing() override {
		return new Wrapper();
	}
};

#endif // !BURGER_H