[上一篇](../Interpreter%20Pattern/README.md)

---

# 💠 额外补充

接下来补充介绍一些设计模式，它们并不属于 GOF 的 23 种核心设计模式，但在实际软件开发过程中仍然非常实用。

补充模式：
* 过滤器模式 Filter
* 空对象模式 Null Object

# 过滤器模式 Filter

> 过滤器模式也称为“**标准模式 Criteria**”

## 1、动机

* 在软件构建过程中，我们经常会面临需要处理大量数据集合的情况。我们可能需要根据不同的条件来过滤数据，这些条件可能会有很多种，而且可能经常变化。
* 如何应对这种条件的频繁变化？

> 过滤器模式允许开发人员使用不同的标准来过滤一组对象，通过逻辑运算以解耦的方式把它们连接起来。这种类型的设计模式属于结构型模式，它结合多个标准来获得单一标准。

## 2、介绍

<dl>
    <dt>意图</dt>
    <dd>允许开发人员使用不同的标准来过滤一组对象，并通过逻辑运算以解耦的方式把它们连接起来。</dd>
    <dt>关键代码</dt>
    <dd>创建不同的过滤器，实现同一个接口。</dd>
</dl>

---

## 3、实现

### 步骤一

首先我们创建一个类 Person，在过滤器模式中其扮演***被过滤的类***的角色，我们将在该类上应用标准。

我们的 Person 类如下：

```cpp
class Person
{

private:
	// 名字
	std::string name;
	// 性别
	std::string gender;
	// 婚姻状况
	std::string maritalStatus;

public:
	inline Person(std::string _name, std::string _gender, std::string _maritalStatus) :
		name(_name), gender(_gender), maritalStatus(_maritalStatus) {
	}

	// 重载 == 运算符
	inline bool operator==(const Person& other) const {
		if (this->name == other.name && this->gender == other.gender && this->maritalStatus == other.maritalStatus) {
			return true;
		}
		return false;
	}
	
	inline std::string getName() {
		return name;
	}
	
	inline std::string getGender() {
		return gender;
	}
	
	inline std::string getMaritalStatus() {
		return maritalStatus;
	}
};
```

> Person 类包含一些基础的成员变量，比如：
> * `name`：名字；
> * `gender`：性别；
> * `maritalStatus`：婚姻状况。
>
> Person 类还公开了一些成员函数用于在外界访问这些成员变量：
> * `getName()`：获取名字；
> * `getGender()`：获取性别；
> * `getMaritalStatus()`：获取婚姻状况。
>
> 此外，Person 类还重载了 `==` 运算符，这是为了方便在过滤器类中进行对象间的比较。

### 步骤二

接下来我们为标准（也就是过滤器）创建一个接口 Criteria：

```cpp
class Criteria
{

public:
	virtual std::vector<Person> meetCriteria(std::vector<Person> persons) = 0;
	virtual ~Criteria() {}
};
```

> Criteria 包含一个纯虚的成员函数 `meetCriteria(std::vector<Person> persons)`。该函数用于过滤满足标准的 Person 对象。

### 步骤三

接下来我们创建实现了 Criteria 类的实体标准（过滤器）类 CriteriaMale、CriteriaFemale、CriteriaSingle 以及两个组合过滤器 AndCriteria 和 OrCriteria：

```cpp
class CriteriaMale :
    public Criteria
{

public:
    inline virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override {
        std::vector<Person> malePersons;
        for (Person person : persons) {
            if (person.getGender() == "Male") {
                malePersons.push_back(person);
            }
        }
        return malePersons;
    }
};
```

> CriteriaMale 用于过滤男性。

```cpp
class CriteriaFemale :
    public Criteria
{

public:
    inline virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override {
        std::vector<Person> femalePersons;
        for (Person person : persons) {
            if (person.getGender() == "Female") {
                femalePersons.push_back(person);
            }
        }
        return femalePersons;
    }
};
```

> CriteriaFemale 用于过滤女性。

```cpp
class CriteriaSingle :
    public Criteria
{

public:
    inline virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override {
        std::vector<Person> singlePersons;
        for (Person person : persons) {
            if (person.getMaritalStatus() == "Single") {
                singlePersons.push_back(person);
            }
        }
        return singlePersons;
    }
};
```

> CriteriaSingle 用于过滤单身人士。

```cpp
class AndCriteria :
    public Criteria
{

private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    inline AndCriteria(Criteria* _criteria, Criteria* _otherCriteria) : 
        criteria(_criteria), otherCriteria(_otherCriteria){
    }

    inline virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override {
        std::vector<Person> firstCriteriaPersons = criteria->meetCriteria(persons);
        return otherCriteria->meetCriteria(firstCriteriaPersons);
    }
};
```

> AndCriteria 用于组合「**且**」过滤器。

```cpp
class OrCriteria :
    public Criteria
{

private:
    Criteria* criteria;
    Criteria* otherCriteria;

public:
    inline OrCriteria(Criteria* _criteria, Criteria* _otherCriteria) :
        criteria(_criteria), otherCriteria(_otherCriteria) {
    }
    
    inline virtual std::vector<Person> meetCriteria(std::vector<Person> persons) override {
        std::vector<Person> firstCriteriaItems = criteria->meetCriteria(persons);
        std::vector<Person> otherCriteriaItems = otherCriteria->meetCriteria(persons);

        for (Person person : otherCriteriaItems) {
            if (std::find(firstCriteriaItems.begin(), firstCriteriaItems.end(), person) == firstCriteriaItems.end()) {
                firstCriteriaItems.push_back(person);
            }
        }
        return firstCriteriaItems;
    }
};
```

> OrCriteria 用于组合「**或**」过滤器。

### 步骤四

在 `main()` 函数中，我们使用不同的标准（过滤器）以及它们的组合来过滤 Person 对象的列表：

```cpp
void printPersons(std::vector<Person> persons) {
	for (auto person : persons) {
		std::cout << "Person : [ Name : " << person.getName()
			<< ", Gender : " << person.getGender()
			<< ", Marital Status : " << person.getMaritalStatus()
			<< " ]" << std::endl;
	}
}

int main() {
	std::vector<Person> persons;

	persons.push_back(Person("Robert", "Male", "Single"));
	persons.push_back(Person("John", "Male", "Married"));
	persons.push_back(Person("Laura", "Female", "Married"));
	persons.push_back(Person("Diana", "Female", "Single"));
	persons.push_back(Person("Mike", "Male", "Single"));
	persons.push_back(Person("Bobby", "Male", "Single"));

	CriteriaMale criteriaMale;
	CriteriaFemale criteriaFemale;
	CriteriaSingle criteriaSingle;
	AndCriteria andCriteria(&criteriaSingle, &criteriaMale);
	OrCriteria orCriteria(&criteriaSingle, &criteriaFemale);

	Criteria& male = criteriaMale;
	Criteria& female = criteriaFemale;
	Criteria& single = criteriaSingle;
	Criteria& singleMale = andCriteria;
	Criteria& singleOrFemale = orCriteria;

	std::cout << "Males: " << std::endl;
	printPersons(male.meetCriteria(persons));

	std::cout << "\nFemales: " << std::endl;
	printPersons(female.meetCriteria(persons));

	std::cout << "\nSingle Males: " << std::endl;
	printPersons(singleMale.meetCriteria(persons));

	std::cout << "\nSingle Or Females: " << std::endl;
	printPersons(singleOrFemale.meetCriteria(persons));
}
```

### 步骤五

执行程序，输出结果：

```plain
Males:
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : John, Gender : Male, Marital Status : Married ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Females:
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]

Single Males:
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Single Or Females:
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
```

### 步骤六

[查看项目类图](https://learn.microsoft.com/zh-cn/visualstudio/ide/class-designer/designing-and-viewing-classes-and-types?view=vs-2022#add-class-diagrams-to-projects)

---

## 4、总结

* 过滤器模式提供了一种灵活、高效的方式来处理数据过滤的问题。在实际软件开发中，过滤器模式被广泛应用于各种需要进行数据过滤的场景。
* 在过滤器模式中，我们可以定义多个过滤器，每个过滤器代表了一个过滤条件。当需要过滤数据时，我们可以动态地组合这些过滤器，从而实现灵活的过滤功能。

---

[下一篇](../Null%20Object%20Pattern/README.md)