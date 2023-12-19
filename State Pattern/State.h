#ifndef STATE_H
#define STATE_H

#include "Context.h"
#include <string>

/// <summary>
/// ������ State �ӿ�
/// </summary>
class State
{

public:
	/// <summary>
	/// ����ִ�ж�������
	/// </summary>
	/// <param name="context">����ĳ��״̬���������</param>
	/// <remark>�����������봫�����ã�����������һ�� Context ��������������״̬��������ԭ����</remark>
	virtual void doAction(Context& context) = 0;
	/// <summary>
	/// ����ת�ַ�������
	/// </summary>
	/// <returns>ת������ַ���</returns>
	virtual std::string toString() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~State() {}
};

#endif // !STATE_H