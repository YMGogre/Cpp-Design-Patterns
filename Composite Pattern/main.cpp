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

	// 打印该组织的所有员工
	std::cout << *CEO << std::endl;
	// `auto&` 允许编译器自动推断变量的类型，并且通过引用的方式绑定到另一个变量；而不是创建一个新的副本。
	for (auto& headEmployee : CEO->getSubordinates()) {
		std::cout << *headEmployee << std::endl;
		for (auto& employee : headEmployee->getSubordinates()) {
			std::cout << *employee << std::endl;
		}
	}

	// 像操作单个对象那样打印该组织的所有员工
	//CEO->print();
}