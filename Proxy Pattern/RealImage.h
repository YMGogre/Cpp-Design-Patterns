#ifndef REALIMAGE_H
#define REALIMAGE_H

#include "Image.h"
#include <string>
#include <iostream>

/// <summary>
/// ʵ�ֳ����� Image ��ʵ���� RealImage
/// </summary>
class RealImage :
	public Image
{

private:
	/// <summary>ͼƬ�ļ�����</summary>
	std::string fileName;

public:
	inline RealImage(std::string _fileName) : fileName(_fileName) {
		loadFromDisk(_fileName);
	}
	/// <summary>
	/// ʵ�ֻ���Ĵ�����ʾ����
	/// </summary>
	inline virtual void display() override {
		std::cout << "Displaying " << fileName << std::endl;
	}
	/// <summary>
	/// �Ӵ��̼���ͼƬ�ļ�
	/// </summary>
	/// <param name="_fileName">�ļ�����</param>
	inline void loadFromDisk(std::string _fileName) {
		std::cout << "Loading " << _fileName << std::endl;
	}
};

#endif // !REALIMAGE_H