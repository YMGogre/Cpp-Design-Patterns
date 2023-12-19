#ifndef RENDERAPI_H
#define RENDERAPI_H

/// <summary>
/// ������ RenderAPI(ʵ�ֲ��ֽӿ�)
/// </summary>
class RenderAPI
{

public:
	/// <summary>
	/// ������ȾԲ�κ���
	/// </summary>
	/// <param name="radius">�뾶</param>
	/// <param name="x">X ����</param>
	/// <param name="y">Y ����</param>
	virtual void renderCircle(int radius, int x, int y) = 0;
	virtual ~RenderAPI() {}
};

#endif // !RENDERAPI_H