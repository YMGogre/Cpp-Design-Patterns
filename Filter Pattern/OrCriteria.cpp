#include "OrCriteria.h"
#include <algorithm>

std::vector<Person> OrCriteria::meetCriteria(std::vector<Person> persons) {
	std::vector<Person> firstCriteriaItems = criteria->meetCriteria(persons);
	std::vector<Person> otherCriteriaItems = otherCriteria->meetCriteria(persons);

	for (Person person : otherCriteriaItems) {
		if (std::find(firstCriteriaItems.begin(), firstCriteriaItems.end(), person) == firstCriteriaItems.end()) {
			firstCriteriaItems.push_back(person);
		}
	}
	return firstCriteriaItems;
}