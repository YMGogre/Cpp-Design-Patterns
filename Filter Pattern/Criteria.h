#ifndef CRITERIA_H
#define CRITERIA_H

#include <vector>
#include "Person.h"

/// <summary>
/// 抽象类 Ceiteria
/// </summary>
class Criteria
{

public:
	/// <summary>
	/// 纯虚过滤函数，用于过滤满足标准的对象
	/// </summary>
	/// <param name="persons">待过滤的对象动态数组</param>
	/// <returns>过滤后（满足标准）的对象动态数组</returns>
	virtual std::vector<Person> meetCriteria(std::vector<Person> persons) = 0;
	virtual ~Criteria() {}
};

#endif // !CRITERIA_H