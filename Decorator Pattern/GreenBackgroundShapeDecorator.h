#ifndef GREENBACKGROUNDSHAPEDECORATOR_H
#define GREENBACKGROUNDSHAPEDECORATOR_H

#include "ShapeDecorator.h"
#include <iostream>

/// <summary>
/// �̳���װ�������� ShapeDecorator �ľ���װ������ GreenBackgroundShapeDecorator
/// </summary>
class GreenBackgroundShapeDecorator :
	public ShapeDecorator
{

private:
	/// <summary>
	/// ����װ�����������һ���µĹ��� ���� ������״����ɫ����
	/// </summary>
	/// <param name="decoratedShape">��װ�ε� Shape ����</param>
	inline void setGreenBackground(Shape& decoratedShape) {
		std::cout << "Background Color: Green" << std::endl;
	}

public:
	inline GreenBackgroundShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	/// <summary>
	/// ��д���������Ⱦ����������µ���Ϊ ���� ������ɫ����
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
		setGreenBackground(decoratedShape);
	}
};

#endif // !GREENBACKGROUNDSHAPEDECORATOR_H