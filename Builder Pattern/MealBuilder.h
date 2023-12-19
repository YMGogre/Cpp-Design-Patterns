#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "VegBurger.h"
#include "ChickenBurger.h"
#include "Coke.h"
#include "Pepsi.h"
#include "Meal.h"

/// <summary>
/// 负责创建 Meal 套餐对象的 MealBuilder
/// </summary>
class MealBuilder
{

public:
	/// <summary>
	/// 准备素食套餐
	/// </summary>
	/// <returns>素食套餐对象</returns>
	Meal prepareVegMeal();
	/// <summary>
	/// 准备非素食套餐
	/// </summary>
	/// <returns>非素食套餐对象</returns>
	Meal prepareNonVegMeal();
};

#endif // !MEALBUILDER_H