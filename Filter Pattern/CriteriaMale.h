#ifndef CRITERIAMALE_H
#define CRITERIAMALE_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// ʵ�ֳ����� Criteria ��ʵ���� CriteriaMale
/// </summary>
class CriteriaMale :
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

#endif // !CRITERIAMALE_H