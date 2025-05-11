#include "sourse.h"

//int a = 0;
//
// // 类域
// // 命名空间域
//
// // 局部域
// // 全局域
//int main()
//{
//	int a = 1;
//
//	printf("%d\n", a);   //如果没有::，优先访问局部域
//
//	                     // ::域作用限定域,::前是void，意味着访问的是全局域
//	printf("%d\n",::a); 
//
//	return 0;
//}

int a = 0;

namespace bit  //命名空间域，可以定义各种类型，函数，变量，结构体
{
	int a = 1;

}  //这里没有;哦

// 局部域->全局域 -> 展开了命名空间域 or 指定访问命名空间域

using namespace bit;  //展开命名空间域，但是展开命名空间会将命名空间域内的变量暴露在全局域，故展开命名空间后，全局域内不得有重复命名变量
                      //故一般不要用展开命名空间，多用指定访问空间域
//如果没有展开命名空间或者指定访问命名空间域的话，是不会主动找命名空间域内的变量

//int main()
//{
//	int a = 2;
//
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	printf("%d\n", bit::a);  //指定访问空间域
//
//
//	return 0;
//}

//2. 命名空间可以嵌套
// test.cpp
namespace N1
{
	int a;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N2
	{
		int c;
		int d;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

//3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
// ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个
// test.h
namespace N1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}
//只要是包含了那个文件，无论你在哪写相同的命名空间域，最终都会合并成一个，当然同一个文件也可以，不同的文件需要用include包含之后
//才会合并为一个，前提是：这两个命名空间域的名字相同


// 展开某个：把常用展开
using std::cout;  //中间不要加namespace
using std::endl;

//int main()
//{
//	int x = 10;
//	// << 流插入运算符，即把“hello world”流入cout，而cout会自动输出，你没有流入cout是空的，自然不会打印到屏幕
//	cout << "hello world" << x << '\n' << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//	cout << "hello world" << endl;
//
//	std::list<int> lt;
//
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	double d = 11.11;
//
//	// 自动识别类型
//	cout << x << " " << d << endl;
//
//	// >> 流提取运算符
//	std::cin >> x >> d;
//	cout << x << " " << d << endl;
//	printf("%d,%.2f\n", x, d);
//	cout << x << " " << d << endl;
//
//
//	return 0;
//}

//缺省参数概念
//缺省参数是声明或定义函数时为函数的参数指定一个缺省值。在调用该函数时，如果没有指定实
//参则采用该形参的缺省值，否则使用指定的实参。
 
//void Func1(int a = 10, int b = 20, int c = 30) //全缺省参数
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//void Func2(int a, int b = 10, int c = 20) //半缺省参数 
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}

//1. 半缺省参数必须从右往左依次来给出，不能间隔着给
//2. 缺省参数不能在函数声明和定义中同时出现，如果在两个文件中，缺省只能在声明给，不能在定义给
//3. 缺省值必须是常量或者全局变量
//4. C语言不支持（编译器不支持）

//函数重载：是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，这
//些同名函数的形参列表(参数个数 或 类型 或 类型顺序)不同，常用来处理实现功能类似数据类型
//不同的问题。
// 1、参数类型不同
// 2、参数个数不同
// 3、参数类型顺序不同
// 4、返回值没有要求
 
// 1、引用做返回值  （减少拷贝提高效率）（大对象/深拷贝类对象--什么是深拷贝以后会讲）
// 2、引用做返回值   修改返回值+获取返回值

//int& count1()  //1.引用返回，返回的是n的别名，可以提升效率，不用在寄存器中开辟一块空间把n赋值
//               //出了函数作用域，对象不在了就不能用引用返回，如果还在就可以用用于返回
//{              //同时要注意，引用返回需要返回的变量是在静态区，即static修饰，如不是，则函数销毁时将n的地址交还给系统，这时可能是随机值
//	static int n = 0;
//	n++;
//	return n;
//}

//2.引用作返回值可以修改返回值
//比如上面count1函数中返回的是n的别名，可以在main函数中写
//    count1()++; 这就会使静态变量n+1，在顺序表链表当中使用较多，用一个引用返回就可以做到 赋值 和 获取 操作

//int main()
//{
//	// 不可以
//	// 引用过程中，权限不能放大
//	const int a = 0;
//	//int& b = a;
//
//	// 可以，c拷贝给d，没有放大权限，因为d的改变不影响c
//	const int c = 0;
//	int d = c;
//
//	// 不可以
//	// 引用过程中，权限可以平移或者缩小
//	int x = 0;
//	int& y = x;
//	const int& z = x;  //这一部分是在缩小z作为别名的权限，就好像铁牛只有宋江能叫，但是李逵很多人都可以叫，但是仍然指的使一个人
//	++x;
//	//++z;
//
//	const int& m = 10;
//
//	double dd = 1.11;
//	int ii = dd;
//
//	const int& rii = dd;
//
//	return 0;
//}

//临时变量具有常性，即不可修改
//无论是 非引用返回时的临时变量，以及 隐式转换中的临时变量 都具有常性
//隐式转换有临时变量
//如下

//void text1()
//{
//	int a = 10;
//	double b = 1.11;
//	if (b > a)    //这里也发生了隐式转换，是 临时变量 = （double）a  ， b>临时变量
//	{
//		cout << "haha" << endl;
//	}
//	a = b;  //这里就发生了隐式转换，其是 临时变量=（int）b; 然后a = 临时变量
//}

//int main()
//{
//	int a = 0;
//	int b = a;
//	auto c = a; // 根据右边的表达式自动推导c的类型
//	auto d = 1 + 1.11; // 根据右边的表达式自动推导d的类型
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	vector<int> v;
//
//	// 类型很长
//	//vector<int>::iterator it = v.begin();
//	// 等价于
//	auto it = v.begin();
//
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator dit = dict.begin();
//	// 等价于
//	auto dit = dict.begin();
//
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5 };
//
//	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
//		arr[i] *= 2;
//
//	for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
//		cout << *p << " ";
//	cout << endl;
//
//	// 适用于数组
//	// 范围for 语法糖
//	// 依次取数组中数据赋值给e
//	// 自动迭代，自动判断结束
//	// for (int x : arr)
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//
//	// 修改数据是不可以的，但是auto&就可以了，不加引用是赋值，只会改变e不会改变arr
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//#define Add(x, y) ((x)+(y))
//
//int main()
//{
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << Add(i, i + 1) << endl;
//	}
//
//	if (Add(10, 20))
//	{
//
//	}
//
//	Add(10, 20) * 20;
//
//	int a = 1, b = 2;
//	Add(a | b, a & b); // (a | b + a & b)
//
//	return 0;
//}

// 宏函数 
// 优点-- 不需要建立栈帧，提高调用效率
// 缺点-- 复杂，容易出错、可读性差、不能调试

// 适用于短小的频繁调用的函数
// inline对于编译器仅仅只是一个建议，最终是否成为inline，编译器自己决定
// 像类似函数就加了inline也会被否决掉
// 1、比较长的函数
// 2、递归函数
// 默认debug模式下，inline不会起作用，否则不方便调试了

//inline int Add(int x, int y)
//{
//	return (x + y) * 10;
//}

//inline是一种以空间换时间的做法，如果编译器将函数当成内联函数处理，在编译阶段，会
//用函数体替换函数调用，缺陷：可能会使目标文件变大，优势：少了调用开销，提高程序运
//行效率

//inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。

//auto for循环

//拷贝元素（适用于只读且元素较小的情况）：
//for (auto element : container) { ... }
//每次循环会创建元素的拷贝，不修改原容器。

//引用元素（需修改元素或避免拷贝）：
//for (auto& element : container) { ... }
//直接引用容器中的元素，可修改原元素。

//NULL实际是一个宏
//#ifndef NULL
//#ifdef __cplusplus
//#define NULL    0
//#else
//#define NULL    ((void *)0)
//#endif
//#endif

//可以看到，NULL可能被定义为字面常量0，或者被定义为无类型指针(void*)的常量。

//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}

//int main()
//{
//	f(0);
//	f(NULL);
//	f(nullptr);
//  f((int*)NULL);
//}

//在C++98中，字面常量0既可以是一个整形数字，也可以是无类型的指针(void*)常量，但是编译器
//默认情况下将其看成是一个整形常量，如果要将其按照指针方式来使用，必须对其进行强转(void*)0。

//1. 在使用nullptr表示指针空值时，不需要包含头文件，因为 nullptr 是 C++11作为新关键字引入的。
//2. 在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。
//3. 为了提高代码的健壮性，在后续表示指针空值时建议最好使用nullptr

