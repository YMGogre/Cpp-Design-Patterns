#ifndef COLOR_H
#define COLOR_H

/// <summary>
/// ������ Color
/// </summary>
class Color {
public:
	/// <summary>
	/// ���������ɫ����
	/// </summary>
	virtual void fill() = 0;
	virtual ~Color() {};
};

#endif // !COLOR_H