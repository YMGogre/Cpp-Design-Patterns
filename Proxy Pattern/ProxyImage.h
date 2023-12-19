#ifndef PROXYIMAGE_H
#define PROXYIMAGE_H

#include "Image.h"
#include "RealImage.h"
#include <string>

/// <summary>
/// ʵ�ֳ����� Image �Ĵ����� ProxyImage
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
	/// ʵ�ֻ���Ĵ�����ʾ����
	/// </summary>
	inline virtual void display() override {
		if (realImage == nullptr) {
			realImage = new RealImage(fileName);
		}
		realImage->display();
	}
};

#endif // !PROXYIMAGE_H