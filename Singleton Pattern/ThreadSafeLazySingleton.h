#ifndef THREADSAFELAZYSINGLETON_H
#define THREADSAFELAZYSINGLETON_H

#include <mutex>

/// <summary>
/// �̰߳�ȫ������ʽ����ģʽ��
/// </summary>
class ThreadSafeLazySingleton {

private:
	static ThreadSafeLazySingleton* instance;
	static std::mutex mutex;		//���廥����

protected:
	/* �ܱ����Ĺ��캯����ζ������̳С�Ȼ����Ҫע����ǣ��ڵ���ģʽ������̳п��ܻ����븴���ԡ�
	   ��Ϊ����ģʽ�ĺ�����ȷ��һ����ֻ��һ��ʵ������������ܹ������Լ���ʵ������ô�Ϳ���Υ����һԭ��
	   ��ˣ������г�ֵ�������Ҫ�̳У�����ͨ�����齫���캯������Ϊ `private`��*/
	ThreadSafeLazySingleton() {}

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	ThreadSafeLazySingleton(const ThreadSafeLazySingleton&) = delete;				// ɾ����Ŀ������캯��
	ThreadSafeLazySingleton& operator=(const ThreadSafeLazySingleton&) = delete;	// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ�̰߳�ȫ������ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� ThreadSafeLazySingleton �Ķ���ָ��</returns>
	static inline ThreadSafeLazySingleton* getInstance() {
		// �й� RAII ���ƽ��ܣ��ɲο���https://zh.cppreference.com/w/cpp/language/raii
		std::lock_guard<std::mutex> lock(mutex);	//ʹ�û��������������
		if (instance == nullptr) {
			instance = new ThreadSafeLazySingleton();
		}
		return instance;
	}
};

#endif // !THREADSAFELAZYSINGLETON_H