#ifndef SHAPECACHE_H
#define SHAPECACHE_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

/// <summary>
/// 原型管理器类，用于管理形状原型
/// </summary>
class ShapeCache
{

private:
	/// <summary>
	/// 使用一张哈希表存储实体类对象
	/// </summary>
	std::unordered_map<std::string, std::unique_ptr<Shape>> shapeMap;

public:
	inline ShapeCache() {
		shapeMap["Rectangle"] = std::make_unique<Rectangle>();
		shapeMap["Ellipse"] = std::make_unique<Ellipse>();
	}
	/// <summary>
	/// 获取形状的克隆
	/// </summary>
	/// <param name="type">形状的类型名称</param>
	/// <returns>抽象类 Shape 的智能指针</returns>
	inline std::unique_ptr<Shape> getShape(const std::string& type) {
		return shapeMap[type]->clone();
	}
};

#endif // !SHAPECACHE_H