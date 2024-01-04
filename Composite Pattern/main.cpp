#include "Employee.h"
#include <iostream>
#include <memory>

int main() {
	auto CEO = std::make_shared<Employee>("John", "CEO", 30000);

	auto headSales = std::make_shared<Employee>("Robert", "Head Sales", 20000);

	auto headMarketing = std::make_shared<Employee>("Michel", "Head Marketing", 20000);

	auto clerk1 = std::make_shared<Employee>("Laura", "Marketing", 10000);
	auto clerk2 = std::make_shared<Employee>("Bob", "Marketing", 10000);

	auto salesExecutive1 = std::make_shared<Employee>("Richard", "Sales", 10000);
	auto salesExecutive2 = std::make_shared<Employee>("Rob", "Sales", 10000);

	CEO->add(headSales);
	CEO->add(headMarketing);

	headSales->add(salesExecutive1);
	headSales->add(salesExecutive2);

	headMarketing->add(clerk1);
	headMarketing->add(clerk2);

	// ��ӡ����֯������Ա��
	std::cout << *CEO << std::endl;
	// `auto&` ����������Զ��ƶϱ��������ͣ�����ͨ�����õķ�ʽ�󶨵���һ�������������Ǵ���һ���µĸ�����
	for (auto& headEmployee : CEO->getSubordinates()) {
		std::cout << *headEmployee << std::endl;
		for (auto& employee : headEmployee->getSubordinates()) {
			std::cout << *employee << std::endl;
		}
	}

	// �������������������ӡ����֯������Ա��
	//CEO->print();
}