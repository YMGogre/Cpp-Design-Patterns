#ifndef CRITERIA_H
#define CRITERIA_H

#include <vector>
#include "Person.h"

/// <summary>
/// ������ Ceiteria
/// </summary>
class Criteria
{

public:
	/// <summary>
	/// ������˺��������ڹ��������׼�Ķ���
	/// </summary>
	/// <param name="persons">�����˵Ķ���̬����</param>
	/// <returns>���˺������׼���Ķ���̬����</returns>
	virtual std::vector<Person> meetCriteria(std::vector<Person> persons) = 0;
	virtual ~Criteria() {}
};

#endif // !CRITERIA_H