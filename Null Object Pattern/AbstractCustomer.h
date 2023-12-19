#ifndef ABSTRACTCUSTOMER_H
#define ABSTRACTCUSTOMER_H

#include <string>

/// <summary>
/// ����ͻ��࣬���Բ����ͻ�������
/// </summary>
class AbstractCustomer
{

protected:
	/// <summary>�ͻ�������</summary>
	std::string name;

public:
	AbstractCustomer(std::string _name) : name(_name) {}
	/// <summary>
	/// ������ͻ��Ƿ�Ϊ�պ���
	/// </summary>
	/// <returns>���� true ���Ϊ�գ����򷵻� false</returns>
	virtual bool isNil() = 0;
	/// <summary>
	/// �����ȡ�ͻ������ֺ���
	/// </summary>
	/// <returns>�ͻ�����</returns>
	virtual std::string getName() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~AbstractCustomer() {}
};

#endif // !ABSTRACTCUSTOMER_H