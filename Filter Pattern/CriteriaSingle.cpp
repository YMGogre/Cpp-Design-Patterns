#include "CriteriaSingle.h"

std::vector<Person> CriteriaSingle::meetCriteria(std::vector<Person> persons) {
	std::vector<Person> singlePersons;
	for (Person person : persons) {
		if (person.getMaritalStatus() == "Single") {
			singlePersons.push_back(person);
		}
	}
	return singlePersons;
}