#ifndef MOUSE_H
#define MOUSE_H

#include "ComputerPart.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// ʵ�ֳ����� ComputerPart ��ʵ������� Mouse
/// </summary>
class Mouse :
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

#endif // !MOUSE_H