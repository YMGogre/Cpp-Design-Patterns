[上一篇](../Memento%20Pattern/README.md)

---

# 💠 “数据结构”模式

常常有一些组件在内部具有特定的数据结构，如果让客户程序依赖这些特定的数据结构，将极大地破坏组件的复用。这时候，将这些特定数据结构封装在内部，在外部提供统一的接口，来实现与特定数据结构无关的访问，是一种行之有效的解决方案。

典型模式：
* 组合模式 Composite
* 迭代器模式 Iterator
* 责任链模式 Chain of Responsibility

# 组合模式 Composite

## 1、动机

* 软件在某些情况下，客户代码过多地依赖于对象容器复杂的内部实现结构，对象容器内部实现结构（而非抽象接口）的变化将引起客户代码的频繁变化，带来了代码的维护性、扩展性等弊端。
* 如何将 “客户代码与复杂的对象容器结构” 解耦？让对象容器自己来实现自身的复杂结构，从而使得客户代码就像处理简单对象一样来处理复杂的对象容器？

> 组合模式，又叫**部分整体模式**，是用于把一组相似的对象当作一个单一的对象。组合模式依据树形结构来组合对象，用来表示部分以及整体层次。这种类型的设计模式属于结构型模式，它创建了对象组的树形结构。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>将对象组合成树形结构以表示"部分-整体"的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。</dd>
    <dt>关键代码</dt>
    <dd>树枝内部组合该接口，并且含有内部属性列表，里面放组合组件类。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个员工类 Employee，它将扮演组合组件类的角色。

```cpp
class Employee
{

private:
	// 名字
	std::string name;
	// 部门
	std::string dept;
	// 薪资
	int salary;
	// 下属
	std::vector<std::shared_ptr<Employee>> subordinates;

public:
	inline Employee(std::string _name, std::string _dept, int _salary) :
		name(_name), dept(_dept), salary(_salary) {
	}

	// 向当前 Employee 的下属员工列表里添加一个 Employee
	inline void add(const std::shared_ptr<Employee> e) {
		subordinates.push_back(e);
	}

	// 从当前 Employee 的下属员工列表里移除指定的 Employee
	inline void remove(const std::shared_ptr<Employee> e) {
		auto item = std::find(subordinates.begin(), subordinates.end(), e);
		if (item != subordinates.end()) {
			subordinates.erase(item);
		}
	}

	// 获取当前员工的下属员工列表
	inline std::vector<std::shared_ptr<Employee>> getSubordinates() {
		return subordinates;
	}

	// 打印当前员工及其下属所有员工的树形层次结构
	inline void print() {
		std::cout << *this << std::endl;
		if (!subordinates.empty()) {
			for (auto subordinate : subordinates) {
				subordinate->print();
			}
		}
	}

	// 声明重载的 << 运算符为友元函数以访问私有成员变量
	friend std::ostream& operator<<(std::ostream& os, const Employee& obj);
};

// 重载 << 运算符
std::ostream& operator<<(std::ostream& os, const Employee& obj) {
	os << ("Employee : [ Name : " + obj.name
		+ ", dept : " + obj.dept + ", salary : "
		+ std::to_string(obj.salary) + " ]");
	return os;
}
```

### 步骤二

在 `main()` 函数中，我们使用 Employee 来创建和打印员工的层次结构：

```cpp
int main() {
	auto CEO = std::make_shared<Employee>("John", "CEO", 30000);

	auto headSales = std::make_shared<Employee>("Robert", "Head Sales", 20000);

	auto headMarketing = std::make_shared<Employee>("Michel", "Head Marketing", 20000);

	auto clerk1 = std::make_shared<Employee>("Laura", "Marketing", 10000);
	auto clerk2 = std::make_shared<Employee>("Bob", "Marketing", 10000);

	auto salesExecutive1 = std::make_shared<Employee>("Richard", "Sales", 10000);
	auto salesExecutive2 = std::make_shared<Employee>("Rob", "Sales", 10000);

	CEO->add(headSales);
	CEO->add(headMarketing);

	headSales->add(salesExecutive1);
	headSales->add(salesExecutive2);

	headMarketing->add(clerk1);
	headMarketing->add(clerk2);

	// 打印该组织的所有员工
	std::cout << *CEO << std::endl;
	// `auto&` 允许编译器自动推断变量的类型，并且通过引用的方式绑定到另一个变量；而不是创建一个新的副本。
	for (auto& headEmployee : CEO->getSubordinates()) {
		std::cout << *headEmployee << std::endl;
		for (auto& employee : headEmployee->getSubordinates()) {
			std::cout << *employee << std::endl;
		}
	}
}
```

> 在 `main()` 函数中，我们仍然是访问了对象组树形结构的所有节点以打印员工层次结构。
>
> 如果我们希望能够像处理简单对象一样处理复杂的对象容器，我们就需要让对象容器自己来处理自身的复杂结构。就像 Employee 类中 `print()` 成员函数做的那样。
>
> 通过 `print()` 函数，我们完成了将 “客户代码与复杂的对象容器结构” 解耦，在客户代码 `main()` 函数中，我们只需简单地处理顶层节点即可：
> 
> ```cpp
> // 打印该组织的所有员工
> CEO->print();
> ```
>
> 上方代码同样可以打印该组织的所有员工。

### 步骤三

执行程序，输出结果：

```plain
Employee : [ Name : John, dept : CEO, salary : 30000 ]
Employee : [ Name : Robert, dept : Head Sales, salary : 20000 ]
Employee : [ Name : Richard, dept : Sales, salary : 10000 ]
Employee : [ Name : Rob, dept : Sales, salary : 10000 ]
Employee : [ Name : Michel, dept : Head Marketing, salary : 20000 ]
Employee : [ Name : Laura, dept : Marketing, salary : 10000 ]
Employee : [ Name : Bob, dept : Marketing, salary : 10000 ]
```

### 步骤四

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 组合模式采用树形结构来实现普遍存在的对象容器，从而将 “一对多” 的关系转化为 “一对一” 的关系，使得客户代码可以一致地（复用）处理对象和对象容器，无需关心处理的是单个的对象，还是组合的对象容器。
* 将 “客户代码与复杂的对象容器结构” 解耦是组合模式的核心思想，解耦之后，客户代码将与纯粹的抽象接口 —— 而非对象容器内部实现结构 —— 发生依赖，从而更能 “应对变化”。

    > 本示例中 Employee 并没有抽象出一个接口，但如果您想的话可以这样做。

* 组合模式在具体实现中，可以让父对象中的子对象反向追溯；如果父对象有频繁的遍历需求，可使用缓存技巧来改善效率。

---

[下一篇](../Iterator%20Pattern/README.md)