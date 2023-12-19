#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;	// ʹ��ǰ�������Ա���ѭ������
// �ο���<https://blog.csdn.net/u010330109/article/details/120800927>

/// <summary>
/// �۲��߳����� Observer
/// </summary>
class Observer
{

protected:
	/// <summary>ָ�����⣨���۲��ߣ���ָ��</summary>
	Subject* subject;

public:
	Observer(Subject* _subject) : subject(_subject) {}
	/// <summary>
	/// ������º���
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Observer() {}
};

#endif // !OBSERVER_H