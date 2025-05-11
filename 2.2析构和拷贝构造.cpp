#include "2.类和对象.h"

//析构函数：与构造函数功能相反，析构函数不是完成对对象本身的销毁，局部对象销毁工作是由
//编译器完成的。而对象在销毁时会自动调用析构函数，完成对象中资源的清理工作。

//特性

//析构函数是特殊的成员函数，其特征如下：
//1. 析构函数名是在类名前加上字符 ~。
//2. 无参数无返回值类型。
//3. 一个类只能有一个析构函数。若未显式定义，系统会自动生成默认的析构函数。注意：析构函数不能重载
//4. 对象生命周期结束时，C++编译系统系统自动调用析构函数。
//5. 如果类中没有申请资源时，析构函数可以不写，直接使用编译器生成的默认析构函数，比如Date类；有资源申请时，一定要写，否则会造成资源泄漏，比如Stack类。

class Stack1
{
public:
	//Stack()
	//{
	//	cout << "Stack()" << endl;

	//	_a = (int*)malloc(sizeof(int) * 4);
	//	if (nullptr == _a)
	//	{
	//		perror("malloc申请空间失败");
	//		return;
	//	}

	//	_capacity = 4;
	//	_top = 0;
	//}

	Stack1(int capacity = 4)
	{
		cout << "Stack()" << endl;

		_a = (int*)malloc(sizeof(int) * capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}

		_capacity = capacity;
		_top = 0;
	}

	// st2(st1)
	Stack1(const Stack1& st)
	{
		_a = (int*)malloc(sizeof(int) * st._capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		}

		memcpy(_a, st._a, sizeof(int) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}

	~Stack1()  //析构函数
	{
		cout << "~Stack()" << endl;
		free(_a);
		_a = nullptr;
		_capacity = _top = 0;
	}

private:
	int* _a = nullptr;
	int _top = 0;
	int _capacity;
};

//1、一般情况下，有动态申请资源，就需要显示写析构函数释放资源
//2、没有动态申请的资源，不需要写析构
//3、需要释放资源的成员都是自定义类型，不需要写析构

//拷贝构造函数：只有单个形参，该形参是对本类类型对象的引用(一般常用const修饰)，在用已存在的类类型对象创建新对象时由编译器自动调用。

//特征

//拷贝构造函数也是特殊的成员函数，其特征如下：
//1. 拷贝构造函数是构造函数的一个重载形式。
//2. 拷贝构造函数的参数只有一个且必须是类类型对象的引用，使用传值方式编译器直接报错，因为会引发无穷递归调用。
//3. 若未显式定义，编译器会生成默认的拷贝构造函数。 默认的拷贝构造函数对象按内存存储按字节序完成拷贝，这种拷贝叫做浅拷贝，或者值拷贝。
//4. 注意:类中如果没有涉及资源申请时，拷贝构造函数是否写都可以; 一旦涉及到资源申请时，则拷贝构造函数是一定要写的，否则就是浅拷贝。
//5. 拷贝构造函数典型调用场景：
//	使用已存在对象创建新对象
//	函数参数类型为类类型对象
//	函数返回值类型为类类型对象

//C++规定:
//内置类型直接拷贝自定义类型必须调用拷贝构造完成拷贝

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)  //拷贝构造，本质仍然是构造函数，用const修饰可以防止写反
	{					 //用&是因为不用开辟新空间，如果不加引用，则会在传参的时候开辟新的类导致赋值时产生新的拷贝构造引起无限递归
		cout << "Date(Date& d)" << endl;
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
		/*d._year = _year;
		d._month = _month;
		d._day = _day;*/
	}

	/*1、内置类型成员完成值拷贝 / 浅拷贝
	2、自定义类型成员会调用他的拷贝构造。*/

	void _print()
	{
		cout << _year << endl;
		cout << _month << endl;
		cout << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	Date d1;
//	Date d2(d1);
//
//	d2._print();
//
//	return 0;
//
//}