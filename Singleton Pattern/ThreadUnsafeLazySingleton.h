#ifndef THREADUNSAFELAZYSINGLETON_H
#define THREADUNSAFELAZYSINGLETON_H

/// <summary>
/// �̲߳���ȫ������ʽ����ģʽ��
/// </summary>
class ThreadUnsafeLazySingleton {

private:
	static ThreadUnsafeLazySingleton* instance;

protected:
	/* �ܱ����Ĺ��캯����ζ������̳С�Ȼ����Ҫע����ǣ��ڵ���ģʽ������̳п��ܻ����븴���ԡ�
	   ��Ϊ����ģʽ�ĺ�����ȷ��һ����ֻ��һ��ʵ������������ܹ������Լ���ʵ������ô�Ϳ���Υ����һԭ��
	   ��ˣ������г�ֵ�������Ҫ�̳У�����ͨ�����齫���캯������Ϊ `private`��*/
	ThreadUnsafeLazySingleton() {}

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	ThreadUnsafeLazySingleton(const ThreadUnsafeLazySingleton&) = delete;				// ɾ����Ŀ������캯��
	ThreadUnsafeLazySingleton& operator=(const ThreadUnsafeLazySingleton&) = delete;	// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ�̲߳���ȫ������ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� ThreadUnsafeLazySingleton �Ķ���ָ��</returns>
	static inline ThreadUnsafeLazySingleton* getInstance() {
		if (instance == nullptr) {
			instance = new ThreadUnsafeLazySingleton();
		}
		return instance;
	}
};

#endif // !THREADUNSAFELAZYSINGLETON_H