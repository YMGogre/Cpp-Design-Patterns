#ifndef PROXYIMAGE_H
#define PROXYIMAGE_H

#include "Image.h"
#include "RealImage.h"
#include <string>

/// <summary>
/// 实现抽象类 Image 的代理类 ProxyImage
/// </summary>
class ProxyImage :
	public Image
{

private:
	RealImage* realImage = nullptr;
	std::string fileName;

public:
	inline ProxyImage(std::string _fileName) : fileName(_fileName) {}
	/// <summary>
	/// 实现基类的纯虚显示函数
	/// </summary>
	inline virtual void display() override {
		if (realImage == nullptr) {
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
};

#endif // !PROXYIMAGE_H