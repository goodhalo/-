#include "2.类和对象.h"

//默认成员函数：用户没有显式实现，编译器会生成的成员函数称为默认成员函数。
//1.构造 2.析构 3.拷贝构造 4.赋值运算符重载 5.普通对象取地址 6.const对象取地址

//class Date
//{
//public:
//	void Init(int year)
//	{
//		// 这里的year到底是成员变量，还是函数形参？
//		_year = year;
//	}
//private:
//	int _year; // _year 公司会把成员变量前面加一个_表示这是成员变量
//	int _month;
//	int _day;
//};

class A
{
public:
	void Print()
	{
		cout << "Print()" << endl;
	}
private:
	int _a;
};

class A1
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
private:
	int _a;
};

//int main()
//{
//	A* p = nullptr;
//	p->Print();  //这个是正常运行，因为print函数不在类中，所以这里不需解引用
//	return 0;
//
//	A1* p1 = nullptr;
//	p1->PrintA();   //这里崩溃，因为printa函数中出现了_a，这个必须解引用，而对空指针进行解引用会导致报错
//	return 0;
//}


//int main()
//{
//	// 类实例化对象/对象定义
//	Stack st1;
//	Stack st2;
//	Stack st3;
//	Stack st4;
//
//	st1.top = 0;  //25行和28行这里的top不是同一个对象，
//	st1.Push(1);  //但是26行的函数跟29行的函数是同一个函数
//					//c++为了节省空间，相同类的不同成员的成员函数全部保存在一个公共空间内，而类本身不含这个函数大小
//	st2.top = 1;
//	st2.Push(1);
//
//	// 对象中只存储的成员变量，没有存储成员函数
//	cout << sizeof(st1) << endl;
//
//
//	A* p = nullptr;
//	p->Print();
//	return 0;
//
//	return 0;
//}

class Date
{
public:
	// 构成函数重载
	// 但是无参调用存在歧义？
	//Date()  //，这个是无参构造函数，跟下面的声明的缺省值存在歧义，无参的构造函数和全缺省的构造函数都称为默认构造函数
	//{
	//	_year = 11;
	//	_month = 1;
	//	_day = 1;
	//}

	Date(int year = 2000, int month = 1, int day = 1)  //这个是全缺省构造函数，无参的构造函数和全缺省的构造函数都称为默认构造函数
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	// 内置类型
	// C++11支持，这里不是初始化，因为这里只是声明
	// 这里给的是默认的缺省值，给编译器生成默认构造函数用，即不使用显性构造函数(即自己写的）时，默认构造函数就会调用这个
	int _year = 1;
	int _month = 1;
	int _day = 1;

	// 自定义类型
	//Stack _st;
};

// 1、一般情况下，有内置类型成员，就需要自己写构造函数，不能用编译器自己生成的。
// 2、全部都是自定义类型成员，可以考虑让编译器自己生成

//int main()
//{
//	// 构造函数的调用跟普通函数也不一样
//	Date d1;
//	//Date d1(); // 不可以这样写，会跟函数声明有点冲突，编译器不好识别
//	Date d2(2023, 11 , 11);
//	d1.Print();
//	d2.Print();
//
//	Date d3;
//	d3.Print();
//
//	//Date d1;
//	//d1.Date();
//	//Date d2;
//	//d2.Date(2023, 1, 1);
//
//	return 0;
//}

