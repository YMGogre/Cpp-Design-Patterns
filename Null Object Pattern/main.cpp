#include "AbstractCustomer.h"
#include "CustomerFactory.h"
#include <string>
#include <iostream>

// 定义静态成员
const std::string CustomerFactory::names[] = {"Rob", "Joe", "Julie"};

int main() {
	AbstractCustomer* customer1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer* customer2 = CustomerFactory::getCustomer("Bob");
	AbstractCustomer* customer3 = CustomerFactory::getCustomer("Julie");
	AbstractCustomer* customer4 = CustomerFactory::getCustomer("Laura");

	std::cout << "Customers" << std::endl;
	std::cout << customer1->getName() << std::endl;
	std::cout << customer2->getName() << std::endl;
	std::cout << customer3->getName() << std::endl;
	std::cout << customer4->getName() << std::endl;
}