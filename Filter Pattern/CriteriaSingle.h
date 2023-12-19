#ifndef CRITERIASINGLE_H
#define CRITERIASINGLE_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// ʵ�ֳ����� Criteria ��ʵ���� CriteriaSingle
/// </summary>
class CriteriaSingle :
    public Criteria
{

public:
    /// <summary>
    /// ʵ�ֻ���Ĵ�����˺��������ڹ��������׼�Ķ���
    /// </summary>
    /// <param name="persons">�����˵Ķ���̬����</param>
    /// <returns>���˺������׼���Ķ���̬����</returns>
    virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override;
};

#endif // !CRITERIASINGLE_H