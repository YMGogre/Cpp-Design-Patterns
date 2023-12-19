#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ��װ�������� ShapeDecorator��ͨ�����캯���ķ������Ƹ�������类ʵ������
/// </summary>
class ShapeDecorator :
	public Shape
{

protected:
	/// <summary>��װ�ε� Shape ����</summary>
	Shape& decoratedShape;
	/// <summary>
	/// �ܱ����Ĺ��캯���Ա��ⱻ���ʵ����
	/// </summary>
	/// <param name="_decoratedShape">��װ�ε� Shape ����</param>
	inline ShapeDecorator(Shape& _decoratedShape) :
		decoratedShape(_decoratedShape) {
	}

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ�����Ⱦ����
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
	}
};

#endif // !SHAPEDECORATOR_H