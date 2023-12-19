#ifndef ORCRITERIA_H
#define ORCRITERIA_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// ʵ�ֳ����� Criteria ��ʵ���� OrCriteria�����������������������׼��
/// </summary>
class OrCriteria :
    public Criteria
{

private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    /// <summary>
    /// ʵ���� OrCriteria��ʹ������ָ���Ĺ���������׼��
    /// </summary>
    /// <param name="_criteria">������һ</param>
    /// <param name="_otherCriteria">��������</param>
    inline OrCriteria(Criteria* _criteria, Criteria* _otherCriteria) :
        criteria(_criteria), otherCriteria(_otherCriteria) {
    }
    /// <summary>
    /// ʵ�ֻ���Ĵ�����˺��������ڹ��������׼�Ķ���
    /// </summary>
    /// <param name="persons">�����˵Ķ���̬����</param>
    /// <returns>���˺������׼���Ķ���̬����</returns>
    virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override;
};

#endif // !ORCRITERIA_H