#ifndef STATICNESTEDCLASSSINGLETON_H
#define STATICNESTEDCLASSSINGLETON_H

/// <summary>
/// ��̬�ڲ���ʽ����ģʽ��
/// </summary>
class StaticNestedClassSingleton {

private:
	StaticNestedClassSingleton() {}

	/// <summary>
	/// ��ֹ�� 2023 �꣬C++ ��׼û�о�̬��ĸ�������ǿ���ͨ�������г�Ա����Ϊ��̬�Դﵽ���ƾ�̬���Ч��
	/// </summary>
	class SingletonHolder {

	private:
		static const StaticNestedClassSingleton INSTANCE;
	public:
		static inline const StaticNestedClassSingleton& getInstance() {
			return INSTANCE;
		}
	};

public:
	// ���������캯���Ϳ�����ֵ��������Ϊɾ������ֹ�������ʵ��������
	StaticNestedClassSingleton(const StaticNestedClassSingleton&) = delete;					// ɾ����Ŀ������캯��
	StaticNestedClassSingleton& operator=(const StaticNestedClassSingleton&) = delete;		// ɾ����Ŀ�����ֵ�����

	/// <summary>
	/// ��ȡ��̬�ڲ���ĵ���ģʽ��Ψһʵ��
	/// </summary>
	/// <returns>���� StaticNestedClassSingleton ��������</returns>
	static inline const StaticNestedClassSingleton& getInstance() {
		return SingletonHolder::getInstance();
	}
};

#endif // !STATICNESTEDCLASSSINGLETON_H