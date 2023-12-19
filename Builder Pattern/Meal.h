#ifndef MEAL_H
#define MEAL_H

#include "Item.h"
#include <iostream>
#include <vector>

/// <summary>
/// �ײ��࣬����һЩ�̶�����Ĳ͵�
/// </summary>
class Meal {

private:
	std::vector<Item*> items;

public:
	/// <summary>
	/// ���ײ����ʳ����Ŀ
	/// </summary>
	/// <param name="item">ʳ����Ŀ����</param>
	inline void addItem(Item* const& item) {
		items.push_back(item);
	}
	/// <summary>
	/// ��ȡ�ײ͵ļ۸�
	/// </summary>
	/// <returns>�ײͼ۸�</returns>
	inline float getCost() {
		float cost = 0.0f;
		for (auto item : items) {
			cost += item->price();
		}
		return cost;
	}
	/// <summary>
	/// չʾ�ײͰ�����ʳ����뵽��׼�������
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