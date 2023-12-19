#ifndef STOPSTATE_H
#define STOPSTATE_H

#include "State.h"
#include "Context.h"
#include <iostream>

/// <summary>
/// ʵ�ֳ����� State ��ʵ���� StopState
/// </summary>
class StopState :
	public State
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ���ִ�ж�������
	/// </summary>
	/// <param name="context">����ĳ��״̬����</param>
	inline virtual void doAction(Context& context) override {
		std::cout << "Player is in stop state" << std::endl;
		context.setState(this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ���ת�ַ�������
	/// </summary>
	/// <returns>ת������ַ���</returns>
	inline virtual std::string toString() override {
		return "Stop State";
	}
};

#endif // !STOPSTATE_H