#ifndef MEAL_H
#define MEAL_H

#include "Item.h"
#include <iostream>
#include <vector>

/// <summary>
/// 套餐类，包含一些固定搭配的餐点
/// </summary>
class Meal {

private:
	std::vector<Item*> items;

public:
	/// <summary>
	/// 向套餐添加食物条目
	/// </summary>
	/// <param name="item">食物条目对象</param>
	inline void addItem(Item* const& item) {
		items.push_back(item);
	}
	/// <summary>
	/// 获取套餐的价格
	/// </summary>
	/// <returns>套餐价格</returns>
	inline float getCost() {
		float cost = 0.0f;
		for (auto item : items) {
			cost += item->price();
		}
		return cost;
	}
	/// <summary>
	/// 展示套餐包含的食物（插入到标准输出流）
	/// </summary>
	inline void showItems() {
		for (auto item : items) {
			std::cout << "Item: " << item->name()
			<< ", Packing: " << item->packing()->pack()
			<< ", Price: " << item->price() << std::endl;
		}
	}

	~Meal() {
		for (auto item : items) {
			delete item;
		}
	}
};

#endif // !MEAL_H