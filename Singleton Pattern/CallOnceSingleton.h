#ifndef CALLONCESINGLETON_H
#define CALLONCESINGLETON_H

#include <memory>
#include <mutex>

/// <summary>
/// std::call_once ʽ����ģʽ��
/// </summary>
class CallOnceSingleton
{

private:
	static std::shared_ptr<CallOnceSingleton> instance;
	static std::once_flag singletonFlag;
	CallOnceSingleton() {}		// ˽�й��캯��

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	CallOnceSingleton(const CallOnceSingleton&) = delete;				// ɾ����Ŀ������캯��
	CallOnceSingleton& operator=(const CallOnceSingleton&) = delete;	// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ std::call_once ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� CallOnceSingleton ������ָ��</returns>
	static inline std::shared_ptr<CallOnceSingleton> getInstance() {
		std::call_once(singletonFlag, [&] {
			instance = std::shared_ptr<CallOnceSingleton>(new CallOnceSingleton());
		});
		return instance;
	}
};

#endif // !CALLONCESINGLETON_H