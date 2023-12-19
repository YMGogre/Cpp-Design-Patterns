#ifndef SHAPE_H
#define SHAPE_H

#include <memory>
#include <string>

/// <summary>
/// ������ Shape
/// </summary>
class Shape
{

public:
	/// <summary>
	/// �����¡���������ڴ�������ĸ���
	/// </summary>
	/// <returns>������ Shape ������ָ��</returns>
	virtual std::unique_ptr<Shape> clone() const = 0;	// �й� const ���γ�Ա�������ο���<https://blog.csdn.net/YMGogre/article/details/126759839#t16>
	/// <summary>
	/// ������Ⱦ����
	/// </summary>
	virtual void render() const = 0;
	/// <summary>
	/// �����ȡ���ͺ���
	/// </summary>
	/// <returns></returns>
	virtual std::string getType() const = 0;
	virtual ~Shape() {}
};

#endif // !SHAPE_H