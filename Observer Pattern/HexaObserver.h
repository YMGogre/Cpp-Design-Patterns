#ifndef HEXAOBSERVER_H
#define HEXAOBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <sstream>
#include <string>

class HexaObserver :
	public Observer
{

public:
	HexaObserver(Subject* _subject) : Observer(_subject) {
		// ���Լ���ӵ����⣨���۲��ߣ��Ĺ۲����б���
		subject->attach(this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����º���
	/// </summary>
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::hex << subject->getState();		// ��ʮ������д�뵽 oss ����
		std::cout << "Hex String: " << oss.str() << std::endl;
	}
};

#endif // !HEXAOBSERVER_H