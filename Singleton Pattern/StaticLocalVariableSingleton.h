#ifndef STATICLOCALVARIABLESINGLETON_H
#define STATICLOCALVARIABLESINGLETON_H

/// <summary>
/// ��̬�ֲ�����ʽ����ģʽ�ࣨ����ʽ��һ�֣�C++ ��׼��֤�������̰߳�ȫ�ģ�
/// </summary>
class StaticLocalVariableSingleton {

private:
	StaticLocalVariableSingleton() {};	// ˽�й��캯��

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	StaticLocalVariableSingleton(const StaticLocalVariableSingleton&) = delete;					// ɾ����Ŀ������캯��
	StaticLocalVariableSingleton& operator=(const StaticLocalVariableSingleton&) = delete;		// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ��̬�ֲ�����ʽ����ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� StaticLocalVariableSingleton �Ķ�������</returns>
	static inline StaticLocalVariableSingleton& getInstance() {
		static StaticLocalVariableSingleton instance;
		return instance;
	}
};

#endif // !STATICLOCALVARIABLESINGLETON_H