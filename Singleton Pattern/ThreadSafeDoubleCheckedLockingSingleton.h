#ifndef THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H
#define THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H

/**
 * 为了解决双检锁式单例模式可能会出现的内存读写 reorder 不安全问题，我们可以使用 std::atomic<T> 创建支持原子操作的对象。
 * 原子操作是指在多线程环境中，一个操作在执行过程中不会被其他线程的操作中断。
 * 这意味着如果您有一个原子变量，您可以安全地在多个线程中对它进行读写，而不需要担心数据竞争或者其他线程安全问题。
 * 原子变量可以看作是一种特殊的类型，它具有类似于普通变量的操作，但这些操作都是原子级别的，即要么全部完成，要么全部未完成。
 * std::atomic<T> 关键字的主要作用不是为了抑制编译器重排，但它能做到这样的事，所以我们可以用它。
 * 有关更多信息，请参考：
 *		* https://gaomf.cn/2020/09/11/Cpp_Volatile_Atomic_Memory_barrier/
 *		* https://www.zhihu.com/question/31490495
 */

#include <mutex>

 /// <summary>
 /// 解决编译器重排问题的双重校验锁式单例模式类
 /// </summary>
class ThreadSafeDoubleCheckedLockingSingleton
{

private:
	static std::atomic<ThreadSafeDoubleCheckedLockingSingleton*> instance;
	static std::mutex mutex;	// 定义互斥锁
	ThreadSafeDoubleCheckedLockingSingleton() {}	// 私有构造函数

public:
	// 将拷贝构造函数和拷贝赋值运算符标记为删除，防止单例类的实例被复制
	ThreadSafeDoubleCheckedLockingSingleton(const ThreadSafeDoubleCheckedLockingSingleton&) = delete;				// 删除类的拷贝构造函数
	ThreadSafeDoubleCheckedLockingSingleton& operator=(const ThreadSafeDoubleCheckedLockingSingleton&) = delete;	// 删除类的拷贝赋值运算符

	/// <summary>
	/// 获取解决编译器重排问题的双重校验锁式单例模式的唯一实例
	/// </summary>
	/// <returns>返回 ThreadSafeDoubleCheckedLockingSingleton 对象指针</returns>
	static inline ThreadSafeDoubleCheckedLockingSingleton* getInstance() {
		ThreadSafeDoubleCheckedLockingSingleton* tmp = instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);	// 获取内存 fence
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(mutex);
			tmp = instance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new ThreadSafeDoubleCheckedLockingSingleton();
				std::atomic_thread_fence(std::memory_order_release);	// 释放内存 fence
				instance.store(tmp, std::memory_order_relaxed);
			}
		}
		return tmp;
	}
};

#endif // !THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H