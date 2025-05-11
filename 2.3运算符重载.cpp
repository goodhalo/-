#include "2.类和对象.h"

//赋值运算符重载
//1. 运算符重载
//C++为了增强代码的可读性引入了运算符重载，运算符重载是具有特殊函数名的函数，也具有其
//返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似。
//
//函数名字为：关键字operator后面接需要重载的运算符符号。
//函数原型：返回值类型 operator操作符(参数列表)
//
//注意：
//不能通过连接其他符号来创建新的操作符：比如operator@
//重载操作符必须有一个类类型参数，不能对内置类型重载
//用于内置类型的运算符，其含义不能改变，例如：内置的整型 + ，不能改变其含义
//作为类成员函数重载时，其形参看起来比操作数数目少1，因为成员函数的第一个参数为隐藏的this
//.*   ::  sizeof  ?:  . 注意以上5个运算符不能重载。这个经常在笔试选择题中出现。

class Date2
{
public:
	Date2(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date2(const Date2& d)
	{
		cout << "Date2(const Date2& d)" << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator<(const Date2& x2)	// 注意：类内运算符重载时只能有且仅有一个参数；类内其他函数可以有多个参数。
	{
		if (this->_year < x2._year) //类内运算符重载可以解决private在类外不能访问的问题
		{
			return true;
		}
		else if (this->_year == x2._year && this->_month < x2._month)
		{
			return true;
		}
		else if (this->_year == x2._year && this->_month == x2._month && this->_day < x2._day)
		{
			return true;
		}

		return false;
	}

	// d4 = d1
	// d1 = d1

	/*赋值运算符重载格式
		参数类型：const T& ，传递引用可以提高传参效率
		返回值类型：T& ，返回引用可以提高返回的效率，有返回值目的是为了支持连续赋值
		检测是否自己给自己赋值
		返回* this ：要复合连续赋值的含义*/

	/*2.赋值运算符只能重载成类的成员函数不能重载成全局函数
	用户没有显式实现时，编译器会生成一个默认赋值运算符重载，以值的方式逐字节拷贝。注
	意：内置类型成员变量是直接赋值的，而自定义类型成员变量需要调用对应类的赋值运算符
	重载完成赋值。*/

	//当然有动态内存时，需要深拷贝，赋值操作符重载就需要自己写

	//引用返回可以链式编程，可以使d4=d3=d2这样的链式操作
	Date2& operator=(const Date2& d)  //赋值操作符重载，使用引用返回
	{
		if (this != &d)  //为了防止d1=d1这样的操作
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this; //this是data的指针，*this可以找到data
	}

	bool operator==(const Date2& x)
	{
		return _year == x._year
			&& _month == x._month
			&& _day == x._day;
	}

	bool operator<=(const Date2& x)
	{
		return *this < x || *this == x;
	}

	bool operator>(const Date2& x)
	{
		return !(*this <= x);  //可以直接这样复用以上运算符重载
	}

	int GetMonthDay(int year, int month)
	{
		static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //这个放static区不用一直创建新函数
		//if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2)
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		else
		{
			return daysArr[month];
		}
	}

	Date2& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}

	// d1 + 100
	Date2 operator+(int day)
	{
		Date2 tmp(*this);
		tmp += day;
		return tmp;

		/*tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			++tmp._month;
			if (tmp._month == 13)
			{
				++tmp._year;
				tmp._month = 1;
			}
		}
		return tmp;
		*/
	}

	// 都要++，前置++返回++以后的对象，后置++返回++之前的对象

	// 前置++
	Date2& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	// 增加这个int参数不是为了接收具体的值，仅仅是占位，跟前置++构成重载
	Date2 operator++(int)
	{
		Date2 tmp = *this;
		*this += 1;

		return tmp;
	}

private:
	int _year;
	int _month;
	int _day;
};

//bool operator<(const Date2& x1, const Date2& x2)	// 注意：类内运算符重载时只能有且仅有一个参数；类内其他函数可以有多个参数。
//{
//	if (x1._year < x2._year)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month < x2._month)
//	{
//		return true;
//	}
//	else if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
//	{
//		return true;
//	}
//
//	return false;
//}

//int main()
//{
//	Date2 d1(2023, 4, 26);
//	Date2 d2(2023, 6, 21);
//
//	//d1 < d2; // 转换成operator<(d1, d2);
//	//operator<(d1, d2);
//
//	//如果运算符重载重名，优先使用全局的
//	d1 < d2; // 转换成d1.operator<(d2);
//	d1.operator<(d2);
//
//	if (d1 < d2)
//	{
//
//	}
//
//	//d1 - d2;  // 有意义
//	//d1 + d2;  // 没意义
//	// 是否要重载运算符，这个运算符对这个类是否有意义
//
//	return 0;
//}

int main()
{
	Date2 d1(2023, 4, 26);
	Date2 d2(2023, 6, 21);
	// 已经存在的两个对象之间复制拷贝        -- 运算符重载函数
	d1 = d2;

	// 用一个已经存在的对象初始化另一个对象  -- 构造函数
	//Date d3(d1);

}