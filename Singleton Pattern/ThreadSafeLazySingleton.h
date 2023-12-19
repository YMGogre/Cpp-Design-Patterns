#ifndef THREADSAFELAZYSINGLETON_H
#define THREADSAFELAZYSINGLETON_H

#include <mutex>

/// <summary>
/// 线程安全的懒汉式单例模式类
/// </summary>
class ThreadSafeLazySingleton {

private:
	static ThreadSafeLazySingleton* instance;
	static std::mutex mutex;		//定义互斥锁

protected:
	/* 受保护的构造函数意味着允许继承。然而需要注意的是，在单例模式中允许继承可能会引入复杂性。
	   因为单例模式的核心是确保一个类只有一个实例。如果子类能够创建自己的实例，那么就可能违反这一原则。
	   因此，除非有充分的理由需要继承，否则通常建议将构造函数声明为 `private`。*/
	ThreadSafeLazySingleton() {}

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	ThreadSafeLazySingleton(const ThreadSafeLazySingleton&) = delete;				// 删除类的拷贝构造函数
	ThreadSafeLazySingleton& operator=(const ThreadSafeLazySingleton&) = delete;	// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取线程安全的懒汉式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 ThreadSafeLazySingleton 的对象指针</returns>
	static inline ThreadSafeLazySingleton* getInstance() {
		// 有关 RAII 机制介绍，可参考：https://zh.cppreference.com/w/cpp/language/raii
		std::lock_guard<std::mutex> lock(mutex);	//使用互斥锁保护代码块
		if (instance == nullptr) {
			instance = new ThreadSafeLazySingleton();
		}
		return instance;
	}
};

#endif // !THREADSAFELAZYSINGLETON_H