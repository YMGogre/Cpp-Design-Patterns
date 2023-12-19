#ifndef COMPUTER_H
#define COMPUTER_H

#include "ComputerPart.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Mouse.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// 实现抽象类 ComputerPart 的实体电脑类 Computer
/// </summary>
class Computer :
	public ComputerPart
{

private:
	ComputerPart* parts[3];

public:
	Computer() : parts{new Mouse(), new Keyboard(), new Monitor()} {}
	/// <summary>
	/// 实现基类的纯虚接受函数。该方法接受一个访问者并将自身引用传入访问者
	/// </summary>
	/// <param name="computerPartVisitor">访问者对象的引用</param>
	inline virtual void accept(ComputerPartVisitor& computerPartVisitor) override {
		// 有关 C++ 求取数组长度的注意事项，请参考：<https://blog.csdn.net/zou_albert/article/details/107340770>
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