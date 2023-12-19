#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

/// <summary>
/// 工厂类，生成基于给定信息的实体类的对象
/// </summary>
class ShapeFactory
{
public:
	/// <summary>
	/// 获取实体类的对象指针方法
	/// </summary>
	/// <param name="shapeType">实体类型名称字符串常量</param>
	/// <returns>返回抽象类 Shape 的指针</returns>
	Shape* getShape(const char* shapeType);
};

#endif // !SHAPEFACTORY_H