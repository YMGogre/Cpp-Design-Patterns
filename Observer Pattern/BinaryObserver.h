#ifndef BINARYOBSERVER_H
#define BINARYOBSERVER_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <bitset>

class BinaryObserver :
	public Observer
{

public:
	BinaryObserver(Subject* _subject) : Observer(_subject) {
		// 将自己添加到主题（被观察者）的观察者列表中
		subject->attach(this);
	}
	/// <summary>
	/// 实现基类的纯虚更新函数
	/// </summary>
	inline virtual void update() override {
		std::string binary = std::bitset<32>(subject->getState()).to_string();
		size_t pos = binary.find_first_not_of('0');
		if (pos != std::string::npos) {
			binary = binary.substr(pos);
		}
		std::cout << "Binary String: " << binary << std::endl;
	}
};

#endif // !BINARYOBSERVER_H