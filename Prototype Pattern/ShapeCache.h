#ifndef SHAPECACHE_H
#define SHAPECACHE_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

/// <summary>
/// ԭ�͹������࣬���ڹ�����״ԭ��
/// </summary>
class ShapeCache
{

private:
	/// <summary>
	/// ʹ��һ�Ź�ϣ��洢ʵ�������
	/// </summary>
	std::unordered_map<std::string, std::unique_ptr<Shape>> shapeMap;

public:
	inline ShapeCache() {
		shapeMap["Rectangle"] = std::make_unique<Rectangle>();
		shapeMap["Ellipse"] = std::make_unique<Ellipse>();
	}
	/// <summary>
	/// ��ȡ��״�Ŀ�¡
	/// </summary>
	/// <param name="type">��״����������</param>
	/// <returns>������ Shape ������ָ��</returns>
	inline std::unique_ptr<Shape> getShape(const std::string& type) {
		return shapeMap[type]->clone();
	}
};

#endif // !SHAPECACHE_H