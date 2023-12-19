#ifndef CRITERIAFEMALE_H
#define CRITERIAFEMALE_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// ʵ�ֳ����� Criteria ��ʵ���� CriteriaFemale
/// </summary>
class CriteriaFemale :
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

#endif // !CRITERIAFEMALE_H