#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include "RenderAPI.h"
#include <iostream>

/// <summary>
/// ʵ�ֳ����� RenderAPI ��ʵ���� RedCircle(����ʵ�ֲ��� 1)
/// </summary>
class RedCircle :
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
		std::cout << "Rendering Circle[ color: red, radius: " 
			<< radius << ", x: " << x << ", y: " << y << "]" << std::endl;
	}
};

#endif // !REDCIRCLE_H