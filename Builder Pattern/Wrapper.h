#ifndef WRAPPER_H
#define WRAPPER_H

#include "Packing.h"

/// <summary>
/// ʵ�ֳ����� Packing ��ʵ���� Wrapper
/// </summary>
class Wrapper :
    public Packing
{

public:
    /// <summary>
    /// ʵ�ֻ���Ĵ����װ����
    /// </summary>
    /// <returns>������װ���ַ���</returns>
    inline virtual std::string pack() override {
        return "Wrapper";
    }
};

#endif // !WRAPPER_H