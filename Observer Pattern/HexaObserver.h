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
		// 将自己添加到主题（被观察者）的观察者列表中
		subject->attach(this);
	}
	/// <summary>
	/// 实现基类的纯虚更新函数
	/// </summary>
	inline virtual void update() override {
		std::ostringstream oss;
		oss << std::hex << subject->getState();		// 将十六进制写入到 oss 流中
		std::cout << "Hex String: " << oss.str() << std::endl;
	}
};

#endif // !HEXAOBSERVER_H