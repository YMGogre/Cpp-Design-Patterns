#ifndef EAGERSINGLETON_H
#define EAGERSINGLETON_H

/// <summary>
/// ����ʽ����ģʽ��
/// </summary>
class EagerSingleton
{
private:
	static EagerSingleton instance;
	EagerSingleton() {};		// ˽�й��캯��

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	EagerSingleton(const EagerSingleton&) = delete;					// ɾ����Ŀ������캯��
	EagerSingleton& operator=(const EagerSingleton&) = delete;		// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ����ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� EagerSingleton �Ķ�������</returns>
	static inline EagerSingleton& getInstance() {
		return instance;
	}
};

#endif // !EAGERSINGLETON_H