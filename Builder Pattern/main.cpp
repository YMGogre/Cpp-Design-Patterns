#include "MealBuilder.h"
#include <iostream>

int main() {
	MealBuilder mealBuilder;

	auto vegMeal = mealBuilder.prepareVegMeal();
	std::cout << "Veg Meal" << std::endl;
	vegMeal.showItems();
	std::cout << "Total Cost: " << vegMeal.getCost() << std::endl;

	auto nonVegMeal = mealBuilder.prepareNonVegMeal();
	std::cout << "\n\nNon-Veg Meal" << std::endl;
	nonVegMeal.showItems();
	std::cout << "Total Cost: " << nonVegMeal.getCost() << std::endl;
}