#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include "Shape.h"

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ���� Ellipse
/// </summary>
class Ellipse :
    public Shape
{
public:
    /// <summary>
    /// ʵ�ֻ���Ĵ�����Ⱦ����
    /// </summary>
    inline virtual void render() override {
        std::cout << "Inside Ellipse::render() method." << std::endl;
    }
};


#endif // !ELLIPSE_H