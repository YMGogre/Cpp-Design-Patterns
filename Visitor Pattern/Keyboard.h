#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "ComputerPart.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// ʵ�ֳ����� ComputerPart ��ʵ������� Keyboard
/// </summary>
class Keyboard :
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

#endif // !KEYBOARD_H