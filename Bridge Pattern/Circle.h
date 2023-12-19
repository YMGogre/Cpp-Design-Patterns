#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "RenderAPI.h"

/// <summary>
/// ʵ�ֳ����� Shape ��ʵ���� Circle(������󲿷�)
/// </summary>
class Circle :
	public Shape
{

private:
	int x, y, radius;

public:
	inline Circle(int _x, int _y, int _radius, RenderAPI* _renderAPI) :
		Shape(_renderAPI), x(_x), y(_y), radius(_radius) {
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����Ⱦ����
	/// </summary>
	inline virtual void render() override {
		renderAPI->renderCircle(radius, x, y);
	}
};

#endif // !CIRCLE_H