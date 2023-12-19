#ifndef GREEN_H
#define GREEN_H

#include <iostream>
#include "Color.h"

/// <summary>
/// ʵ�ֳ����� Color ��ʵ���� Green
/// </summary>
class Green :
    public Color
{
public:
    /// <summary>
    /// ʵ�ֻ���Ĵ��������ɫ����
    /// </summary>
    inline virtual void fill() override {
        std::cout << "Inside Green::fill() method." << std::endl;
    }
};

#endif // !GREEN_H