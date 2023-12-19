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
		// 将自己添加到主题（被观察者）的观察者列表中
		subject->attach(this);
	}
	/// <summary>
	/// 实现基类的纯虚更新函数
	/// </summary>
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::oct << subject->getState();		// 将八进制写入到 oss 流中
		std::cout << "Octal String: " << oss.str() << std::endl;
	}
};

#endif // !OCTALOBSERVER_H