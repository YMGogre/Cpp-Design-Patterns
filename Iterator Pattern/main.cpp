#include "Iterator.h"
#include "NameRepository.h"
#include <vector>
#include <string>
#include <memory>
#include <iostream>

int main() {
	std::vector<std::string> names = { "Robert" , "John" ,"Julie" , "Lora" };
	NameRepository namesRepository(names);
	std::unique_ptr<Iterator<std::string>> iter = namesRepository.getIterator();
	for (iter; iter->hasNext();) {
		std::string name = iter->next();
		std::cout << "Name : " << name << std::endl;
	}
}