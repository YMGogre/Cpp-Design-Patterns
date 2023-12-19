#ifndef BLUE_H
#define BLUE_H

#include <iostream>
#include "Color.h"

/// <summary>
/// 实现抽象类 Color 的实体类 Blue
/// </summary>
class Blue :
    public Color
{
public:
    /// <summary>
    /// 实现基类的纯虚填充颜色函数
    /// </summary>
    inline virtual void fill() override {
        std::cout << "Inside Blue::fill() method." << std::endl;
    }
};

#endif // !BLUE_H