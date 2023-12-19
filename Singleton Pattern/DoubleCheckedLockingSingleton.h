#ifndef DOUBLECHECKEDLOCKINGSINGLETON_H
#define DOUBLECHECKEDLOCKINGSINGLETON_H

#include <mutex>

/// <summary>
/// ˫��У����ʽ����ģʽ��
/// </summary>
class DoubleCheckedLockingSingleton {

private:
	static DoubleCheckedLockingSingleton* instance;
	static std::mutex mutex;		//���廥����
	DoubleCheckedLockingSingleton() {}		//˽�й��캯��

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	DoubleCheckedLockingSingleton(const DoubleCheckedLockingSingleton&) = delete;				// ɾ����Ŀ������캯��
	DoubleCheckedLockingSingleton& operator=(const DoubleCheckedLockingSingleton&) = delete;	// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ˫��У�����ĵ���ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� DoubleCheckedLockingSingleton ����ָ��</returns>
	static inline DoubleCheckedLockingSingleton* getInstance() {
		if (instance == nullptr) {
			// �й� RAII ���ƽ��ܣ��ɲο���https://zh.cppreference.com/w/cpp/language/raii
			std::lock_guard<std::mutex> lock(mutex);	//ʹ�û��������������
			if (instance == nullptr) {
				instance = new DoubleCheckedLockingSingleton();
			}
		}
		return instance;
	}
};

#endif // !DOUBLECHECKEDLOCKINGSINGLETON_H
