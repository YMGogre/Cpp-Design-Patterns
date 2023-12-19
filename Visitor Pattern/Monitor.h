#ifndef MONITOR_H
#define MONITOR_H

#include "ComputerPart.h"
#include "ComputerPartVisitor.h"

/// <summary>
/// 实现抽象类 ComputerPart 的实体显示器类 Monitor
/// </summary>
class Monitor :
	public ComputerPart
{

public:
	/// <summary>
	/// 实现基类的纯虚接受函数。该方法接受一个访问者并将自身引用传入访问者
	/// </summary>
	/// <param name="computerPartVisitor">访问者对象的引用</param>
	inline virtual void accept(ComputerPartVisitor& computerPartVisitor) override {
		computerPartVisitor.visit(*this);
	}
};

#endif // !MONITOR_H