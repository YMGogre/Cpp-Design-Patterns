#include "Image.h"
#include "ProxyImage.h"
#include <iostream>

int main() {
	Image* image = new ProxyImage("test_10mb.jpg");

	// ͼ�񽫴Ӵ��̼���
	image->display();
	std::cout << std::endl;
	// ͼ����Ҫ�Ӵ��̼���
	image->display();
}