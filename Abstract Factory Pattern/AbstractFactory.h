#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Shape.h"
#include "Color.h"

/// <summary>
/// 抽象工厂类 AbstractFactory
/// </summary>
class AbstractFactory {
public:
	/// <summary>
	/// 纯虚获取形状函数
	/// </summary>
	/// <param name="shape">形状名称</param>
	/// <returns>返回抽象类 Shape 的指针</returns>
	virtual Shape* getShape(const char* shape) = 0;
	/// <summary>
	/// 纯虚获取颜色函数
	/// </summary>
	/// <param name="color">颜色名称</param>
	/// <returns>返回抽象类 Color 的指针</returns>
	virtual Color* getColor(const char* color) = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~AbstractFactory() {};
};

#endif // !ABSTRACTFACTORY_H