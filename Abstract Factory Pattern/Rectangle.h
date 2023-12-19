#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ���� Rectangle
/// </summary>
class Rectangle :
    public Shape
{
public:
    /// <summary>
    /// ʵ�ֻ���Ĵ�����Ⱦ����
    /// </summary>
    inline virtual void render() override {
        std::cout << "Inside Rectangle::render() method." << std::endl;
    }
};

#endif // !RECTANGLE_H