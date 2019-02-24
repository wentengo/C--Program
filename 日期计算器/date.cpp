#include "date.h"
int Date::operator-(const Date& d)
{
	Date tmp = *this;
	Date cur = d;
	int num = 0, flag = 0;
	if (tmp > cur)
	{
		tmp = d;
		cur = *this;
		flag = 1;
	}
	while (cur > tmp)
	{
		tmp += 1;
		num++;
	}
	if (flag)
		num = -num;
	return num;
}
Date Date::operator-(int days)
{
	if (days < 0)
	{
		days = -days;
		return *this + days;
	}
	Date tmp(*this);
	if (days == 0)
		return tmp;
	tmp._day -= days;
	while (tmp._day <= 0)
	{
		if (tmp._month == 1)
		{
			tmp._year--;
			tmp._month = 12;
		}
		else
			tmp._month--;
		tmp._day += Getmonth(tmp._year, tmp._month);
	}
	return tmp;
}
Date& Date::operator-=(int days)
{
	Date tmp(*this);
	tmp = (*this) - days;
	*this = tmp;
	return *this;
}
Date Date::operator+(int days)
{
	if (days < 0)
	{
		days = -days;
		return *this - days;
	}
	Date tmp(*this);
	if (days == 0)
		return tmp;
	tmp._day += days;
	while (tmp._day>Getmonth(tmp._year, tmp._month))
	{
		if (tmp._month == 12)
		{
			tmp._year++;
			tmp._month = 1;
		}
		else
			tmp._month++;
		tmp._day -= Getmonth(tmp._year, tmp._month);
	}
	return tmp;
}
Date& Date::operator+=(int days)
{
	Date tmp(*this);
	tmp = (*this) + days;
	*this = tmp;
	return *this;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		if (_month == d._month)
		{
			if (_day > d._day)
				return true;
		}
	}
	return false;
}
bool Date::operator>=(const Date& d)
{
	return (*this > d) || (*this == d);
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return (*this < d) || (*this == d);
}
bool Date::operator==(const Date& d)
{
	return (_year == d._year) && (_month == d._month) && (_day == d._day);
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}