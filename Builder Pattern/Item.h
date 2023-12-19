#ifndef ITEM_H
#define ITEM_H

#include "Packing.h"

/// <summary>
/// ��ʾʳ����Ŀ�ĳ����� Item
/// </summary>
class Item {

public:
	/// <summary>
	/// �������ƺ���
	/// </summary>
	/// <returns>����ʳ��������ַ���</returns>
	virtual std::string name() = 0;
	/// <summary>
	/// �����װ����
	/// </summary>
	/// <returns>���ر�ʾʳ���װ�ĳ����� Packing ��ָ��</returns>
	virtual Packing* packing() = 0;
	/// <summary>
	/// ����۸���
	/// </summary>
	/// <returns>����ʳ��ļ۸�</returns>
	virtual float price() = 0;
	virtual ~Item() {}
};

#endif // !ITEM_H