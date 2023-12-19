#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

/// <summary>
/// 实现抽象类 Shape 的实体类 Rectangle
/// </summary>
class Rectangle :
    public Shape
{
public:
    /// <summary>
    /// 实现基类的纯虚渲染函数
    /// </summary>
    inline virtual void render() override {
        std::cout << "Inside Rectangle::render() method." << std::endl;
    }
};

#endif // !RECTANGLE_H