#ifndef COLDDRINK_H
#define COLDDRINK_H

#include "Item.h"
#include "Bottle.h"

/// <summary>
/// ����ʵ�ֳ����� Item �ĳ����� ColdDrink
/// </summary>
class ColdDrink :
	public Item
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ����װ����
	/// </summary>
	/// <returns>���ر�ʾʳ���װ�ĳ����� Packing ��ָ��</returns>
	inline virtual Packing* packing() override {
		return new Bottle();
	}
};

#endif // !COLDDRINK_H