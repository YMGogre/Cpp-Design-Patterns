#ifndef SHAPE_H
#define SHAPE_H

/// <summary>
/// ������Ԫ�� Shape
/// </summary>
class Shape {
public:
	/// <summary>
	/// ������Ⱦ����
	/// </summary>
	virtual void render() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Shape() {};
};

#endif // !SHAPE_H