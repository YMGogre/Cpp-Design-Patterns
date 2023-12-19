#ifndef COLORFACTORY_H
#define COLORFACTORY_H

#include "Green.h"
#include "Blue.h"
#include "AbstractFactory.h"

/// <summary>
/// ʵ�ֳ��󹤳��� AbstractFactory ��ʵ�幤���� ColorFactory
/// </summary>
class ColorFactory :
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

#endif // !COLORFACTORY_H