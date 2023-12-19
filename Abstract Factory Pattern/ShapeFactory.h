#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Rectangle.h"
#include "Ellipse.h"
#include "AbstractFactory.h"

/// <summary>
/// ʵ�ֳ��󹤳��� AbstractFactory ��ʵ�幤���� ShapeFactory
/// </summary>
class ShapeFactory :
    public AbstractFactory
{
    /// <summary>
    /// ʵ�ֻ���Ĵ����ȡ��״����
    /// </summary>
    /// <param name="shapeType">ʵ�����������ַ�������</param>
    /// <returns>���س����� Shape ��ָ��</returns>
    virtual Shape* getShape(const char* shapeType) override;
    /// <summary>
    /// ʵ�ֻ���Ĵ����ȡ��ɫ����
    /// </summary>
    /// <param name="colorType">ʵ�����������ַ�������</param>
    /// <returns>���س����� Color ��ָ��</returns>
    virtual Color* getColor(const char* colorType) override;
};

#endif // !SHAPEFACTORY_H