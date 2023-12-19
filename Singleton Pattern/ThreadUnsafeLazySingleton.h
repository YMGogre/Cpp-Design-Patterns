#ifndef THREADUNSAFELAZYSINGLETON_H
#define THREADUNSAFELAZYSINGLETON_H

/// <summary>
/// 线程不安全的懒汉式单例模式类
/// </summary>
class ThreadUnsafeLazySingleton {

private:
	static ThreadUnsafeLazySingleton* instance;

protected:
	/* 受保护的构造函数意味着允许继承。然而需要注意的是，在单例模式中允许继承可能会引入复杂性。
	   因为单例模式的核心是确保一个类只有一个实例。如果子类能够创建自己的实例，那么就可能违反这一原则。
	   因此，除非有充分的理由需要继承，否则通常建议将构造函数声明为 `private`。*/
	ThreadUnsafeLazySingleton() {}

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	ThreadUnsafeLazySingleton(const ThreadUnsafeLazySingleton&) = delete;				// 删除类的拷贝构造函数
	ThreadUnsafeLazySingleton& operator=(const ThreadUnsafeLazySingleton&) = delete;	// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取线程不安全的懒汉式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 ThreadUnsafeLazySingleton 的对象指针</returns>
	static inline ThreadUnsafeLazySingleton* getInstance() {
		if (instance == nullptr) {
			instance = new ThreadUnsafeLazySingleton();
		}
		return instance;
	}
};

#endif // !THREADUNSAFELAZYSINGLETON_H