#ifndef WRAPPER_H
#define WRAPPER_H

#include "Packing.h"

/// <summary>
/// 实现抽象类 Packing 的实体类 Wrapper
/// </summary>
class Wrapper :
    public Packing
{

public:
    /// <summary>
    /// 实现基类的纯虚包装函数
    /// </summary>
    /// <returns>表征包装的字符串</returns>
    inline virtual std::string pack() override {
        return "Wrapper";
    }
};

#endif // !WRAPPER_H