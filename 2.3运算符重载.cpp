#include "2.��Ͷ���.h"

//��ֵ���������
//1. ���������
//C++Ϊ����ǿ����Ŀɶ�����������������أ�����������Ǿ������⺯�����ĺ�����Ҳ������
//����ֵ���ͣ����������Լ������б��䷵��ֵ����������б�����ͨ�ĺ������ơ�
//
//��������Ϊ���ؼ���operator�������Ҫ���ص���������š�
//����ԭ�ͣ�����ֵ���� operator������(�����б�)
//
//ע�⣺
//����ͨ���������������������µĲ�����������operator@
//���ز�����������һ�������Ͳ��������ܶ�������������
//�����������͵���������京�岻�ܸı䣬���磺���õ����� + �����ܸı��京��
//��Ϊ���Ա��������ʱ�����βο������Ȳ�������Ŀ��1����Ϊ��Ա�����ĵ�һ������Ϊ���ص�this
//.*   ::  sizeof  ?:  . ע������5��������������ء���������ڱ���ѡ�����г��֡�

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

	bool operator<(const Date2& x2)	// ע�⣺�������������ʱֻ�����ҽ���һ�������������������������ж��������
	{
		if (this->_year < x2._year) //������������ؿ��Խ��private�����ⲻ�ܷ��ʵ�����
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

	/*��ֵ��������ظ�ʽ
		�������ͣ�const T& ���������ÿ�����ߴ���Ч��
		����ֵ���ͣ�T& ���������ÿ�����߷��ص�Ч�ʣ��з���ֵĿ����Ϊ��֧��������ֵ
		����Ƿ��Լ����Լ���ֵ
		����* this ��Ҫ����������ֵ�ĺ���*/

	/*2.��ֵ�����ֻ�����س���ĳ�Ա�����������س�ȫ�ֺ���
	�û�û����ʽʵ��ʱ��������������һ��Ĭ�ϸ�ֵ��������أ���ֵ�ķ�ʽ���ֽڿ�����ע
	�⣺�������ͳ�Ա������ֱ�Ӹ�ֵ�ģ����Զ������ͳ�Ա������Ҫ���ö�Ӧ��ĸ�ֵ�����
	������ɸ�ֵ��*/

	//��Ȼ�ж�̬�ڴ�ʱ����Ҫ�������ֵ���������ؾ���Ҫ�Լ�д

	//���÷��ؿ�����ʽ��̣�����ʹd4=d3=d2��������ʽ����
	Date2& operator=(const Date2& d)  //��ֵ���������أ�ʹ�����÷���
	{
		if (this != &d)  //Ϊ�˷�ֹd1=d1�����Ĳ���
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this; //this��data��ָ�룬*this�����ҵ�data
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
		return !(*this <= x);  //����ֱ�����������������������
	}

	int GetMonthDay(int year, int month)
	{
		static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //�����static������һֱ�����º���
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

	// ��Ҫ++��ǰ��++����++�Ժ�Ķ��󣬺���++����++֮ǰ�Ķ���

	// ǰ��++
	Date2& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	// �������int��������Ϊ�˽��վ����ֵ��������ռλ����ǰ��++��������
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

//bool operator<(const Date2& x1, const Date2& x2)	// ע�⣺�������������ʱֻ�����ҽ���һ�������������������������ж��������
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
//	//d1 < d2; // ת����operator<(d1, d2);
//	//operator<(d1, d2);
//
//	//����������������������ʹ��ȫ�ֵ�
//	d1 < d2; // ת����d1.operator<(d2);
//	d1.operator<(d2);
//
//	if (d1 < d2)
//	{
//
//	}
//
//	//d1 - d2;  // ������
//	//d1 + d2;  // û����
//	// �Ƿ�Ҫ���������������������������Ƿ�������
//
//	return 0;
//}

int main()
{
	Date2 d1(2023, 4, 26);
	Date2 d2(2023, 6, 21);
	// �Ѿ����ڵ���������֮�临�ƿ���        -- ��������غ���
	d1 = d2;

	// ��һ���Ѿ����ڵĶ����ʼ����һ������  -- ���캯��
	//Date d3(d1);

}