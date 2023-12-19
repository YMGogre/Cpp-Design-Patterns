#include "CriteriaMale.h"

std::vector<Person> CriteriaMale::meetCriteria(std::vector<Person> persons) {
	std::vector<Person> malePersons;
	for (Person person : persons) {
		if (person.getGender() == "Male") {
			malePersons.push_back(person);
		}
	}
	return malePersons;
}