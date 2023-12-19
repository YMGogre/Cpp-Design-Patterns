#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Shape.h"
#include "Color.h"

/// <summary>
/// ���󹤳��� AbstractFactory
/// </summary>
class AbstractFactory {
public:
	/// <summary>
	/// �����ȡ��״����
	/// </summary>
	/// <param name="shape">��״����</param>
	/// <returns>���س����� Shape ��ָ��</returns>
	virtual Shape* getShape(const char* shape) = 0;
	/// <summary>
	/// �����ȡ��ɫ����
	/// </summary>
	/// <param name="color">��ɫ����</param>
	/// <returns>���س����� Color ��ָ��</returns>
	virtual Color* getColor(const char* color) = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~AbstractFactory() {};
};

#endif // !ABSTRACTFACTORY_H