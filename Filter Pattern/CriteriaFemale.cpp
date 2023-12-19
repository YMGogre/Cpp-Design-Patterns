#include "CriteriaFemale.h"

std::vector<Person> CriteriaFemale::meetCriteria(std::vector<Person> persons) {
	std::vector<Person> femalePersons;
	for (Person person : persons) {
		if (person.getGender() == "Female") {
			femalePersons.push_back(person);
		}
	}
	return femalePersons;
}