#ifndef IMAGE_H
#define IMAGE_H

/// <summary>
/// 抽象类 Image
/// </summary>
class Image
{

public:
	/// <summary>
	/// 纯虚显示函数
	/// </summary>
	virtual void display() = 0;
	/// <summary>
	/// 虚析构函数
	/// </summary>
	virtual ~Image() {}
};

#endif // !IMAGE_H