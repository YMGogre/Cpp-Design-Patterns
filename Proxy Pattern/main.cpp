#include "Image.h"
#include "ProxyImage.h"
#include <iostream>

int main() {
	Image* image = new ProxyImage("test_10mb.jpg");

	// 图像将从磁盘加载
	image->display();
	std::cout << std::endl;
	// 图像不需要从磁盘加载
	image->display();
}