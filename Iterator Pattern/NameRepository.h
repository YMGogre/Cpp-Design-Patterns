#ifndef NAMEREPOSITORY_H
#define NAMEREPOSITORY_H

#include "Container.h"
#include <string>
#include <vector>
#include <memory>
#include "Iterator.h"

/// <summary>
/// 实现抽象类 Container 的实体容器类 NameRepository。该类有实现了 Iterator 接口的内部类 NameIterator
/// </summary>
class NameRepository :
	public Container<std::string>
{

private:
	class NameIterator :
		public Iterator<std::string>
	{

	public:
		NameIterator(Container<std::string>& _container) : Iterator(_container) {}
		inline virtual bool hasNext() override {
			return index < container.size();
		}
		inline virtual std::string next() override {
			if (this->hasNext()) {
				return container[index++];
			}
			return std::string();
		}
	};

public:
	NameRepository(const std::vector<std::string>& init_vec) : Container{ init_vec } {}
	inline virtual std::unique_ptr<Iterator<std::string>> getIterator() override {
		return std::make_unique<NameIterator>(*this);
	}
};

#endif // !NAMEREPOSITORY_H