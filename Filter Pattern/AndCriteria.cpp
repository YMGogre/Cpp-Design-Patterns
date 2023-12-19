#include "AndCriteria.h"

std::vector<Person> AndCriteria::meetCriteria(std::vector<Person> persons) {
	std::vector<Person> firstCriteriaPersons = criteria->meetCriteria(persons);
	return otherCriteria->meetCriteria(firstCriteriaPersons);
}