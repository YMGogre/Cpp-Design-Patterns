#ifndef REALIMAGE_H
#define REALIMAGE_H

#include "Image.h"
#include <string>
#include <iostream>

/// <summary>
/// 实现抽象类 Image 的实体类 RealImage
/// </summary>
class RealImage :
	public Image
{

private:
	/// <summary>图片文件名称</summary>
	std::string fileName;

public:
	inline RealImage(std::string _fileName) : fileName(_fileName) {
		loadFromDisk(_fileName);
	}
	/// <summary>
	/// 实现基类的纯虚显示函数
	/// </summary>
	inline virtual void display() override {
		std::cout << "Displaying " << fileName << std::endl;
	}
	/// <summary>
	/// 从磁盘加载图片文件
	/// </summary>
	/// <param name="_fileName">文件名称</param>
	inline void loadFromDisk(std::string _fileName) {
		std::cout << "Loading " << _fileName << std::endl;
	}
};

#endif // !REALIMAGE_H