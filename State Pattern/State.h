#ifndef STATE_H
#define STATE_H

#include "Context.h"
#include <string>

/// <summary>
/// 抽象类 State 接口
/// </summary>
class State
{

public:
	/// <summary>
	/// 纯虚执行动作函数
	/// </summary>
	/// <param name="context">带有某个状态的类的引用</param>
	/// <remark>函数参数必须传递引用，否则函数将在一个 Context 副本对象上设置状态，而不是原对象</remark>
	virtual void doAction(Context& context) = 0;
	/// <summary>
	/// 纯虚转字符串函数
	/// </summary>
	/// <returns>转换后的字符串</returns>
	virtual std::string toString() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~State() {}
};

#endif // !STATE_H