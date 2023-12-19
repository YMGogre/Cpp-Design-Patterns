#include "MealBuilder.h"

Meal MealBuilder::prepareVegMeal() {
	Meal meal;
	meal.addItem(new VegBurger());
	meal.addItem(new Coke());
	return meal;
}

Meal MealBuilder::prepareNonVegMeal() {
	Meal meal;
	meal.addItem(new ChickenBurger());
	meal.addItem(new Pepsi());
	return meal;
}