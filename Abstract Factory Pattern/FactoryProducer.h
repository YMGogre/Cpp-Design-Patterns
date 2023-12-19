#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "AbstractFactory.h"
#include "ShapeFactory.h"
#include "ColorFactory.h"

/// <summary>
/// ����������/�������࣬ͨ��������״����ɫ��Ϣ����ȡ����
/// </summary>
class FactoryProducer
{
public:
	/// <summary>
	/// ��ȡ����������ͨ��������״������ɫ��Ϣ����ȡ����
	/// </summary>
	/// <param name="choice">��״������ɫ��Ϣ�ַ�������</param>
	/// <returns>���س��󹤳��� AbstractFactory ��ָ��</returns>
	static AbstractFactory* getFactory(const char* choice);
};

#endif // !FACTORYPRODUCER_H