#ifndef COLOR_H
#define COLOR_H

/// <summary>
/// 抽象类 Color
/// </summary>
class Color {
public:
	/// <summary>
	/// 纯虚填充颜色函数
	/// </summary>
	virtual void fill() = 0;
	virtual ~Color() {};
};

#endif // !COLOR_H