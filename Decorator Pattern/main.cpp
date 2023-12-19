#include "Ellipse.h"
#include "ShapeDecorator.h"
#include "RedBorderShapeDecorator.h"
#include "GreenBackgroundShapeDecorator.h"
#include <iostream>

int main() {
	Ellipse ellipse;
	RedBorderShapeDecorator redEllipse(ellipse);
	// װ������Ƕ�װ�װװ����
	GreenBackgroundShapeDecorator redGreenEllipse(redEllipse);

	std::cout << "Ellipse with normal border" << std::endl;
	ellipse.render();

	std::cout << "\nEllipse of red border" << std::endl;
	redEllipse.render();

	std::cout << "\nEllipse of red border and green background" << std::endl;
	redGreenEllipse.render();

	/**
	 * ��ע�⣬main ����������ֱ��ͨ�����������˳�Ա����������ζ���� main ������
	 * ���ǲ�û��ʹ�� C++ �Ķ�̬���ԡ�Ȼ�����ⲻӰ������չʾװ����ģʽ��
	 * װ����ģʽ�Ĺؼ������ܹ��ڲ��޸�ԭ�ж�����������£�Ϊ��������µĹ��ܡ�
	 * ����ͨ������һ��װ��������ʵ�ֵģ������װ��ԭ�ж��󣬲��ṩ�˶������Ϊ��
	 */
}