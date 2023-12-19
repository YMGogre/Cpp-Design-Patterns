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
		// ���Լ���ӵ����⣨���۲��ߣ��Ĺ۲����б���
		subject->attach(this);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����º���
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