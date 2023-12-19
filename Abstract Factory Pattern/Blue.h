#ifndef BLUE_H
#define BLUE_H

#include <iostream>
#include "Color.h"

/// <summary>
/// ʵ�ֳ����� Color ��ʵ���� Blue
/// </summary>
class Blue :
    public Color
{
public:
    /// <summary>
    /// ʵ�ֻ���Ĵ��������ɫ����
    /// </summary>
    inline virtual void fill() override {
        std::cout << "Inside Blue::fill() method." << std::endl;
    }
};

#endif // !BLUE_H