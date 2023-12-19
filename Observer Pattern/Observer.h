#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;	// 使用前向声明以避免循环依赖
// 参考：<https://blog.csdn.net/u010330109/article/details/120800927>

/// <summary>
/// 观察者抽象类 Observer
/// </summary>
class Observer
{

protected:
	/// <summary>指向主题（被观察者）的指针</summary>
	Subject* subject;

public:
	Observer(Subject* _subject) : subject(_subject) {}
	/// <summary>
	/// 纯虚更新函数
	/// </summary>
	virtual void update() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Observer() {}
};

#endif // !OBSERVER_H