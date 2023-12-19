#ifndef SHAPE_H
#define SHAPE_H

#include "RenderAPI.h"

/// <summary>
/// ������ Shape(���󲿷ֽӿ�)
/// </summary>
class Shape
{

protected:
	RenderAPI* renderAPI;
	inline Shape(RenderAPI* _renderAPI) : renderAPI(_renderAPI) {}

public:
	/// <summary>
	/// ������Ⱦ����
	/// </summary>
	virtual void render() = 0;
	virtual ~Shape() {
		delete renderAPI;
	}
	/** �Ƿ�Ҫ�������� `delete renderAPI; ` ȡ���ڸ�ָ����ڴ��Ƿ��� Shape �ฺ�𴴽������ٵġ�
	  * �������ǹ�ע���ص��ǡ����ģʽ�������Բ�Ҫ̫�����ڴ��������⡣
	  * һ������ֻ���������ģʽ��صĺ��Ĵ��뼴�ɡ�
	  */
};

#endif // !SHAPE_H