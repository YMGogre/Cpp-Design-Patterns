#ifndef ANDCRITERIA_H
#define ANDCRITERIA_H

#include "Criteria.h"
#include <vector>
#include "Person.h"

/// <summary>
/// ʵ�ֳ����� Criteria ��ʵ���� AndCriteria�����������������������׼��
/// </summary>
class AndCriteria :
    public Criteria
{

private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    /// <summary>
    /// ʵ���� AndCriteria��ʹ������ָ���Ĺ���������׼��
    /// </summary>
    /// <param name="_criteria">������һ</param>
    /// <param name="_otherCriteria">��������</param>
    inline AndCriteria(Criteria* _criteria, Criteria* _otherCriteria) : 
        criteria(_criteria), otherCriteria(_otherCriteria){
    }
    /// <summary>
    /// ʵ�ֻ���Ĵ�����˺��������ڹ��������׼�Ķ���
    /// </summary>
    /// <param name="persons">�����˵Ķ���̬����</param>
    /// <returns>���˺������׼���Ķ���̬����</returns>
    virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override;
};

#endif // !ANDCRITERIA_H