#ifndef _DATE__H_
#define _DATE__H_

#include "iostream"
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1)//构造函数
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (_year < 1990 || _month<1 || _month>12 || _day<1 || _day>Getmonth(_year, _month))
		{
			cout << "日期非法" << endl;
			return;
		}
	}
	bool Leapyear(int year)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return true;
		return false;
	}
	int Getmonth(int year, int month)
	{
		int mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (Leapyear(year))
			mon[2] = 29;
		return mon[month];
	}
	Date(const Date& d)                               //拷贝构造
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& _cout, const Date d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
	//计算
	int operator-(const Date& d);                     //两个日期差
	Date operator+(int days);
	Date& operator+=(int days);
	Date operator-(int days);
	Date& operator-=(int days);
	Date& operator++();      //++d
	Date operator++(int);    //d++
	Date& operator--();      //--d
	Date operator--(int);    //d--
	//比较
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	~Date()                                         //析构函数
	{}
private:
	int _year;
	int _month;
	int _day;
};
#endif