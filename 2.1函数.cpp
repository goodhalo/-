#include "2.��Ͷ���.h"

void Stack::Init(int defaultCapacity)     /*����������.h�ļ��У���Ա�����������.cpp�ļ��У�ע�⣺��Ա������ǰ��Ҫ������::*/
{
	a = (int*)malloc(sizeof(int) * capacity);   //�������ں���������������룬����������ʶ����Ϊinline����
	if (nullptr == a)
	{
		perror("malloc����ռ�ʧ��");
		return;
	}

	capacity = defaultCapacity;
	top = 0;
}

