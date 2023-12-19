#include "Person.h"
#include "Criteria.h"
#include "CriteriaMale.h"
#include "CriteriaFemale.h"
#include "CriteriaSingle.h"
#include "AndCriteria.h"
#include "OrCriteria.h"
#include <vector>
#include <iostream>

void printPersons(std::vector<Person> persons) {
	for (auto person : persons) {
		std::cout << "Person : [ Name : " << person.getName()
			<< ", Gender : " << person.getGender()
			<< ", Marital Status : " << person.getMaritalStatus()
			<< " ]" << std::endl;
	}
}

int main() {
	std::vector<Person> persons;

	persons.push_back(Person("Robert", "Male", "Single"));
	persons.push_back(Person("John", "Male", "Married"));
	persons.push_back(Person("Laura", "Female", "Married"));
	persons.push_back(Person("Diana", "Female", "Single"));
	persons.push_back(Person("Mike", "Male", "Single"));
	persons.push_back(Person("Bobby", "Male", "Single"));

	CriteriaMale criteriaMale;
	CriteriaFemale criteriaFemale;
	CriteriaSingle criteriaSingle;
	AndCriteria andCriteria(&criteriaSingle, &criteriaMale);
	OrCriteria orCriteria(&criteriaSingle, &criteriaFemale);

	Criteria& male = criteriaMale;
	Criteria& female = criteriaFemale;
	Criteria& single = criteriaSingle;
	Criteria& singleMale = andCriteria;
	Criteria& singleOrFemale = orCriteria;

	std::cout << "Males: " << std::endl;
	printPersons(male.meetCriteria(persons));

	std::cout << "\nFemales: " << std::endl;
	printPersons(female.meetCriteria(persons));

	std::cout << "\nSingle Males: " << std::endl;
	printPersons(singleMale.meetCriteria(persons));

	std::cout << "\nSingle Or Females: " << std::endl;
	printPersons(singleOrFemale.meetCriteria(persons));
}