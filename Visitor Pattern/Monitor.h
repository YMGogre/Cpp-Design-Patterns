#ifndef MONITOR_H
#define MONITOR_H

#include "ComputerPart.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// ʵ�ֳ����� ComputerPart ��ʵ����ʾ���� Monitor
/// </summary>
class Monitor :
	public ComputerPart
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ܺ������÷�������һ�������߲����������ô��������
	/// </summary>
	/// <param name="computerPartVisitor">�����߶��������</param>
	inline virtual void accept(ComputerPartVisitor& computerPartVisitor) override {
		computerPartVisitor.visit(*this);
	}
};

#endif // !MONITOR_H