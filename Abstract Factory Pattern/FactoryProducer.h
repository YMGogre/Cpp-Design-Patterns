#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "AbstractFactory.h"
#include "ShapeFactory.h"
#include "ColorFactory.h"

/// <summary>
/// 工厂创造器/生成器类，通过传递形状或颜色信息来获取工厂
/// </summary>
class FactoryProducer
{
public:
	/// <summary>
	/// 获取工厂方法，通过传递形状或者颜色信息来获取工厂
	/// </summary>
	/// <param name="choice">形状或者颜色信息字符串常量</param>
	/// <returns>返回抽象工厂类 AbstractFactory 的指针</returns>
	static AbstractFactory* getFactory(const char* choice);
};

#endif // !FACTORYPRODUCER_H