#ifndef COMPUTER_H
#define COMPUTER_H

#include "ComputerPart.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Mouse.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// ʵ�ֳ����� ComputerPart ��ʵ������� Computer
/// </summary>
class Computer :
	public ComputerPart
{

private:
	ComputerPart* parts[3];

public:
	Computer() : parts{new Mouse(), new Keyboard(), new Monitor()} {}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ܺ������÷�������һ�������߲����������ô��������
	/// </summary>
	/// <param name="computerPartVisitor">�����߶��������</param>
	inline virtual void accept(ComputerPartVisitor& computerPartVisitor) override {
		// �й� C++ ��ȡ���鳤�ȵ�ע�������ο���<https://blog.csdn.net/zou_albert/article/details/107340770>
		auto length = sizeof(parts) / sizeof(parts[0]);
		for (int i = 0; i < length; i++) {
			parts[i]->accept(computerPartVisitor);
		}
		computerPartVisitor.visit(*this);
	}
	virtual ~Computer() {
		for (auto& part : parts) {
			delete part;
		}
	}
};

#endif // !COMPUTER_H