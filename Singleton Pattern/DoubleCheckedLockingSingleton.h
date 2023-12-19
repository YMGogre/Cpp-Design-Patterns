#ifndef DOUBLECHECKEDLOCKINGSINGLETON_H
#define DOUBLECHECKEDLOCKINGSINGLETON_H

#include <mutex>

/// <summary>
/// 双重校验锁式单例模式类
/// </summary>
class DoubleCheckedLockingSingleton {

private:
	static DoubleCheckedLockingSingleton* instance;
	static std::mutex mutex;		//定义互斥锁
	DoubleCheckedLockingSingleton() {}		//私有构造函数

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	DoubleCheckedLockingSingleton(const DoubleCheckedLockingSingleton&) = delete;				// 删除类的拷贝构造函数
	DoubleCheckedLockingSingleton& operator=(const DoubleCheckedLockingSingleton&) = delete;	// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取双重校验锁的单例模式的唯一实例
	/// </summary>
	/// <returns>返回 DoubleCheckedLockingSingleton 对象指针</returns>
	static inline DoubleCheckedLockingSingleton* getInstance() {
		if (instance == nullptr) {
			// 有关 RAII 机制介绍，可参考：https://zh.cppreference.com/w/cpp/language/raii
			std::lock_guard<std::mutex> lock(mutex);	//使用互斥锁保护代码块
			if (instance == nullptr) {
				instance = new DoubleCheckedLockingSingleton();
			}
		}
		return instance;
	}
};

#endif // !DOUBLECHECKEDLOCKINGSINGLETON_H
