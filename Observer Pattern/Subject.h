#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;

/// <summary>
/// 主题（被观察者）类
/// </summary>
class Subject
{

private:
	/// <summary>维护一个观察者列表</summary>
	vector<Observer*> observers;
	/// <summary>主题（被观察者）的状态</summary>
	int state;

public:
	/// <summary>
	/// 获取主题（被观察者）状态
	/// </summary>
	/// <returns>主题（被观察者）状态</returns>
	inline int getState() {
		return state;
	}
	/// <summary>
	/// 通知所有的观察者
	/// </summary>
	inline void notifyAllObservers() {
		for (auto observer : observers) {
			observer->update();
		}
	}
	/// <summary>
	/// 设置主题（被观察者）状态
	/// </summary>
	/// <param name="_state">目标状态</param>
	inline void setState(int _state) {
		state = _state;
		notifyAllObservers();
	}
	/// <summary>
	/// 添加观察者
	/// </summary>
	/// <param name="observer">抽象观察者类的指针</param>
	inline void attach(Observer* observer) {
		observers.push_back(observer);
	}
};

#endif // !SUBJECT_H