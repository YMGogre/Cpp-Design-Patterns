#ifndef STARTSTATE_H
#define STARTSTATE_H

#include "State.h"
#include "Context.h"
#include <string>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� State ��ʵ���� StartState
/// </summary>
class StartState :
	public State
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ���ִ�ж�������
	/// </summary>
	/// <param name="context">����ĳ��״̬����</param>
	inline virtual void doAction(Context& context) override {
		std::cout << "Player is in start state" << std::endl;
		context.setState(this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���ת�ַ�������
	/// </summary>
	/// <returns>ת������ַ���</returns>
	inline virtual std::string toString() override {
		return "Start State";
	}
};

#endif // !STARTSTATE_H