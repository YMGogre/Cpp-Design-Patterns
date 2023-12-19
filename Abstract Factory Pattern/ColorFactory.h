#ifndef COLORFACTORY_H
#define COLORFACTORY_H

#include "Green.h"
#include "Blue.h"
#include "AbstractFactory.h"

/// <summary>
/// 实现抽象工厂类 AbstractFactory 的实体工厂类 ColorFactory
/// </summary>
class ColorFactory :
    public AbstractFactory
{
    /// <summary>
    /// 实现基类的纯虚获取形状函数
    /// </summary>
    /// <param name="shapeType">实体类型名称字符串常量</param>
    /// <returns>返回抽象类 Shape 的指针</returns>
    virtual Shape* getShape(const char* shapeType) override;
    /// <summary>
    /// 实现基类的纯虚获取颜色函数
    /// </summary>
    /// <param name="colorType">实体类型名称字符串常量</param>
    /// <returns>返回抽象类 Color 的指针</returns>
    virtual Color* getColor(const char* colorType) override;
};

#endif // !COLORFACTORY_H