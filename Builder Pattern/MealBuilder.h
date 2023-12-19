#ifndef MEALBUILDER_H
#define MEALBUILDER_H

#include "VegBurger.h"
#include "ChickenBurger.h"
#include "Coke.h"
#include "Pepsi.h"
#include "Meal.h"

/// <summary>
/// ���𴴽� Meal �ײͶ���� MealBuilder
/// </summary>
class MealBuilder
{

public:
	/// <summary>
	/// ׼����ʳ�ײ�
	/// </summary>
	/// <returns>��ʳ�ײͶ���</returns>
	Meal prepareVegMeal();
	/// <summary>
	/// ׼������ʳ�ײ�
	/// </summary>
	/// <returns>����ʳ�ײͶ���</returns>
	Meal prepareNonVegMeal();
};

#endif // !MEALBUILDER_H