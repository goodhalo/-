#pragma once
#include "sourse.h"

class Stack  //没有实例化对象时，这里都是声明，但是仍占1byte的字节大小
{
public:
	// 成员函数
	void Init(int defaultCapacity = 4);        /*声明和定义全部放在类体中，需注意 : 成员函数如果在类中定义，编译器可能会将其当成内联函数处理。*/
												/*类声明放在.h文件中，成员函数定义放在.cpp文件中，注意：成员函数名前需要加类名::*/
												//如果有缺省值，缺省值放在声明
	/*Stack(Stack& const sk) {
		this->a = (int*)malloc(sizeof(int)*sk.capacity);
		this->top = sk.top;
		this->capacity = sk.capacity;
	}*/


	void Push(int x)
	{
		//...
		a[top++] = x;
	}

	void Destroy()
	{
		free(a);
		a = nullptr;
		top = capacity;
	}

	~Stack()
	{
		free(this->a);
		a = nullptr;
		top = 0;
		capacity = 0;
	}
	// ....
//private:
	// 成员变量
	int* a;   //声明，本质不开空间，如果开空间，就变成定义了，所以只有实例化的时候才会定义
	int top;  //这里就像是cad图纸，只有实例化才会把房子造出来
	int capacity = 0; //当然，也可以给缺省值，给默认构造函数用的，如果没有初始化成员变量，就会自动赋值给它这个缺省值
};

