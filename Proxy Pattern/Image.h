#ifndef IMAGE_H
#define IMAGE_H

/// <summary>
/// ������ Image
/// </summary>
class Image
{

public:
	/// <summary>
	/// ������ʾ����
	/// </summary>
	virtual void display() = 0;
	/// <summary>
	/// ����������
	/// </summary>
	virtual ~Image() {}
};

#endif // !IMAGE_H