#ifndef CRITERIAFEMALE_H
#define CRITERIAFEMALE_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// 实现抽象类 Criteria 的实体类 CriteriaFemale
/// </summary>
class CriteriaFemale :
    public Criteria
{

public:
    /// <summary>
    /// 实现基类的纯虚过滤函数，用于过滤满足标准的对象
    /// </summary>
    /// <param name="persons">待过滤的对象动态数组</param>
    /// <returns>过滤后（满足标准）的对象动态数组</returns>
    virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override;
};

#endif // !CRITERIAFEMALE_H