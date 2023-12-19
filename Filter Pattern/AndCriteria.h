#ifndef ANDCRITERIA_H
#define ANDCRITERIA_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// 实现抽象类 Criteria 的实体类 AndCriteria，用于组合两个过滤器（标准）
/// </summary>
class AndCriteria :
    public Criteria
{

private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    /// <summary>
    /// 实例化 AndCriteria，使用两个指定的过滤器（标准）
    /// </summary>
    /// <param name="_criteria">过滤器一</param>
    /// <param name="_otherCriteria">过滤器二</param>
    inline AndCriteria(Criteria* _criteria, Criteria* _otherCriteria) : 
        criteria(_criteria), otherCriteria(_otherCriteria){
    }
    /// <summary>
    /// 实现基类的纯虚过滤函数，用于过滤满足标准的对象
    /// </summary>
    /// <param name="persons">待过滤的对象动态数组</param>
    /// <returns>过滤后（满足标准）的对象动态数组</returns>
    virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override;
};

#endif // !ANDCRITERIA_H