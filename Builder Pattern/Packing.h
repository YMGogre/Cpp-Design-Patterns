#ifndef PACKING_H
#define PACKING_H

#include <string>

/// <summary>
/// ��ʾʳ���װ�ĳ����� Packing
/// </summary>
class Packing {

public:
	/// <summary>
	/// �����װ����
	/// </summary>
	/// <returns>������װ���ַ���</returns>
	virtual std::string pack() = 0;
	virtual ~Packing() {}
};

#endif // !PACKING_H