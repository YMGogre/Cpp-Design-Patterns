#ifndef THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H
#define THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H

/**
 * Ϊ�˽��˫����ʽ����ģʽ���ܻ���ֵ��ڴ��д reorder ����ȫ���⣬���ǿ���ʹ�� std::atomic<T> ����֧��ԭ�Ӳ����Ķ���
 * ԭ�Ӳ�����ָ�ڶ��̻߳����У�һ��������ִ�й����в��ᱻ�����̵߳Ĳ����жϡ�
 * ����ζ���������һ��ԭ�ӱ����������԰�ȫ���ڶ���߳��ж������ж�д��������Ҫ�������ݾ������������̰߳�ȫ���⡣
 * ԭ�ӱ������Կ�����һ����������ͣ���������������ͨ�����Ĳ���������Щ��������ԭ�Ӽ���ģ���Ҫôȫ����ɣ�Ҫôȫ��δ��ɡ�
 * std::atomic<T> �ؼ��ֵ���Ҫ���ò���Ϊ�����Ʊ��������ţ������������������£��������ǿ���������
 * �йظ�����Ϣ����ο���
 *		* https://gaomf.cn/2020/09/11/Cpp_Volatile_Atomic_Memory_barrier/
 *		* https://www.zhihu.com/question/31490495
 */

#include <mutex>

 /// <summary>
 /// ������������������˫��У����ʽ����ģʽ��
 /// </summary>
class ThreadSafeDoubleCheckedLockingSingleton
{

private:
	static std::atomic<ThreadSafeDoubleCheckedLockingSingleton*> instance;
	static std::mutex mutex;	// ���廥����
	ThreadSafeDoubleCheckedLockingSingleton() {}	// ˽�й��캯��

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	ThreadSafeDoubleCheckedLockingSingleton(const ThreadSafeDoubleCheckedLockingSingleton&) = delete;				// ɾ����Ŀ������캯��
	ThreadSafeDoubleCheckedLockingSingleton& operator=(const ThreadSafeDoubleCheckedLockingSingleton&) = delete;	// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ������������������˫��У����ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� ThreadSafeDoubleCheckedLockingSingleton ����ָ��</returns>
	static inline ThreadSafeDoubleCheckedLockingSingleton* getInstance() {
		ThreadSafeDoubleCheckedLockingSingleton* tmp = instance.load(std::memory_order_relaxed);
		std::atomic_thread_fence(std::memory_order_acquire);	// ��ȡ�ڴ� fence
		if (tmp == nullptr) {
			std::lock_guard<std::mutex> lock(mutex);
			tmp = instance.load(std::memory_order_relaxed);
			if (tmp == nullptr) {
				tmp = new ThreadSafeDoubleCheckedLockingSingleton();
				std::atomic_thread_fence(std::memory_order_release);	// �ͷ��ڴ� fence
				instance.store(tmp, std::memory_order_relaxed);
			}
		}
		return tmp;
	}
};

#endif // !THREADSAFEDOUBLECHECKEDLOCKINGSINGLETON_H