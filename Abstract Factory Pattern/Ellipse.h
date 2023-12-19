#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include "Shape.h"

/// <summary>
/// 实现抽象类 Shape 的实体类 Ellipse
/// </summary>
class Ellipse :
    public Shape
{
public:
    /// <summary>
    /// 实现基类的纯虚渲染函数
    /// </summary>
    inline virtual void render() override {
        std::cout << "Inside Ellipse::render() method." << std::endl;
    }
};


#endif // !ELLIPSE_H