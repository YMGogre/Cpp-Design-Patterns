#ifndef GREEN_H
#define GREEN_H

#include <iostream>
#include "Color.h"

/// <summary>
/// 实现抽象类 Color 的实体类 Green
/// </summary>
class Green :
    public Color
{
public:
    /// <summary>
    /// 实现基类的纯虚填充颜色函数
    /// </summary>
    inline virtual void fill() override {
        std::cout << "Inside Green::fill() method." << std::endl;
    }
};

#endif // !GREEN_H