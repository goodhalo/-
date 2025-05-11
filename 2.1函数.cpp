#include "2.类和对象.h"

void Stack::Init(int defaultCapacity)     /*类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::*/
{
	a = (int*)malloc(sizeof(int) * capacity);   //这里由于函数的声明定义分离，编译器不会识别其为inline函数
	if (nullptr == a)
	{
		perror("malloc申请空间失败");
		return;
	}

	capacity = defaultCapacity;
	top = 0;
}

