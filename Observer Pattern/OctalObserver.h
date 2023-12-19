#ifndef OCTALOBSERVER_H
#define OCTALOBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <sstream>
#include <string>

class OctalObserver :
	public Observer
{

public:
	OctalObserver(Subject* _subject) : Observer(_subject) {
		// ���Լ���ӵ����⣨���۲��ߣ��Ĺ۲����б���
		subject->attach(this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����º���
	/// </summary>
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::oct << subject->getState();		// ���˽���д�뵽 oss ����
		std::cout << "Octal String: " << oss.str() << std::endl;
	}
};

#endif // !OCTALOBSERVER_H