#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

/// <summary>
/// �����࣬���ɻ��ڸ�����Ϣ��ʵ����Ķ���
/// </summary>
class ShapeFactory
{
public:
	/// <summary>
	/// ��ȡʵ����Ķ���ָ�뷽��
	/// </summary>
	/// <param name="shapeType">ʵ�����������ַ�������</param>
	/// <returns>���س����� Shape ��ָ��</returns>
	Shape* getShape(const char* shapeType);
};

#endif // !SHAPEFACTORY_H