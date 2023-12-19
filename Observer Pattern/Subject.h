#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;

/// <summary>
/// ���⣨���۲��ߣ���
/// </summary>
class Subject
{

private:
	/// <summary>ά��һ���۲����б�</summary>
	vector<Observer*> observers;
	/// <summary>���⣨���۲��ߣ���״̬</summary>
	int state;

public:
	/// <summary>
	/// ��ȡ���⣨���۲��ߣ�״̬
	/// </summary>
	/// <returns>���⣨���۲��ߣ�״̬</returns>
	inline int getState() {
		return state;
	}
	/// <summary>
	/// ֪ͨ���еĹ۲���
	/// </summary>
	inline void notifyAllObservers() {
		for (auto observer : observers) {
			observer->update();
		}
	}
	/// <summary>
	/// �������⣨���۲��ߣ�״̬
	/// </summary>
	/// <param name="_state">Ŀ��״̬</param>
	inline void setState(int _state) {
		state = _state;
		notifyAllObservers();
	}
	/// <summary>
	/// ��ӹ۲���
	/// </summary>
	/// <param name="observer">����۲������ָ��</param>
	inline void attach(Observer* observer) {
		observers.push_back(observer);
	}
};

#endif // !SUBJECT_H