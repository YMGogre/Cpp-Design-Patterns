#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include "RenderAPI.h"
#include <iostream>

/// <summary>
/// ʵ�ֳ����� RenderAPI ��ʵ���� GreenCircle(����ʵ�ֲ��� 2)
/// </summary>
class GreenCircle :
	public RenderAPI
{

public:
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ȾԲ�κ���
	/// </summary>
	/// <param name="radius">�뾶</param>
	/// <param name="x">X ����</param>
	/// <param name="y">Y ����</param>
	inline virtual void renderCircle(int radius, int x, int y) override {
		std::cout << "Rendering Circle[ color: green, radius: "
			<< radius << ", x: " << x << ", y: " << y << "]" << std::endl;
	}
};

#endif // !GREENCIRCLE_H