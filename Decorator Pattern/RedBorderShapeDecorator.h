#ifndef REDBORDERSHAPEDECORATOR_H
#define REDBORDERSHAPEDECORATOR_H

#include "ShapeDecorator.h"
#include <iostream>

/// <summary>
/// �̳���װ�������� ShapeDecorator �ľ���װ������ RedBorderShapeDecorator
/// </summary>
class RedBorderShapeDecorator :
	public ShapeDecorator
{

private:
	/// <summary>
	/// ����װ�����������һ���µĹ��� ���� ������״�ĺ�ɫ�߿�
	/// </summary>
	/// <param name="decoratedShape">��װ�ε� Shape ����</param>
	inline void setRedBorder(Shape& decoratedShape) {
		std::cout << "Border Color: Red" << std::endl;
	}

public:
	inline RedBorderShapeDecorator(Shape& _decoratedShape) :
		ShapeDecorator(_decoratedShape) {
	}
	/// <summary>
	/// ��д���������Ⱦ����������µ���Ϊ ���� ���ú�ɫ�߿�
	/// </summary>
	inline virtual void render() override {
		decoratedShape.render();
		setRedBorder(decoratedShape);
	}
};

#endif // !REDBORDERSHAPEDECORATOR_H