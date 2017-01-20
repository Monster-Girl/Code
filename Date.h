#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
	friend ostream& operator <<(ostream& _cout, const Date& date);
	friend istream& operator >>(istream& _cin, Date& date);
public:
	Date(int year = 1990, int month = 1, int day = 1);
	Date(const Date& date);
	Date& operator=(const Date& date);
	Date& operator++();
	Date operator++(int);
	Date operator+(int day);
	Date operator-(int day);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& date);
	bool operator<(const Date& date);
	bool operator==(const Date& date);
	bool operator!=(const Date& date);
	bool operator>=(const Date& date);
	bool operator<=(const Date& date);

private:
	bool IsLeapYear(int year)
	{
		return((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
	}

	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		static int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if ((month == 2) && (IsLeapYear(year)))
		{
			day += 1;
		}
		return day;
	}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator <<(ostream& _cout, const Date& date)
{
	_cout << date._year << "/" << date._month << "/" << date._day << endl;
	return _cout;
}

istream& operator >>(istream& _cin, Date& date)
{
	_cin >> date._year >> date._month >> date._day;
	return _cin;
}

Date::Date(int year, int month, int day)
{
	if (year > 0
		&& ((month > 0) && (month<13))
		&& ((day>0) && (day <= GetMonthDay(year, month))))
	{
		_year = year;
		_month = month;
		_day = day;
	}

	else
	{
		cout << "the date is illegal!" << endl;
	}
}

Date::Date(const Date& date)
:_year(date._year)
, _month(date._month)
, _day(date._day)
{}

Date& Date::operator=(const Date& date)
{
	if (this != &date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}
	return *this;
}

Date& Date::operator++()
{
	int days = GetMonthDay(_year, _month);
	if (_day < days)
	{
		_day++;
	}
	else if (_day == days)
	{
		_day = 1;
		if (_month < 12)
		{
			_month++;
		}
		else
		{
			_month = 1;
			_year++;
		}
	}
	else
	{
		assert(false);
	}
	return *this;
}

Date& Date::operator++()
{
	Date tmp = *this;
	(*this) =(*this) + 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	++(*this);
	return tmp;
}

Date Date::operator +(int day)
{
	Date tmp = *this;
	if (day<0)
	{
		day = -day;
		return tmp - day;
	}
	tmp._day += day;
	while (tmp._day>GetMonthDay(tmp._year,tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		if (tmp._month < 12)
			tmp._month++;
		else
		{
			tmp._year++;
		}
	}
	return tmp;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp._day -= day;
	while (tmp._day <=0)
	{
		if (tmp._month == 1)
		{
			tmp._year--;
			tmp._month = 12;
		}
		else
		{
			tmp._month--;
		}

		tmp._day += GetMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}

Date& Date::operator--()
{
	(*this) = (*this) - 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	(*this) = (*this) - 1;
	return tmp;
}

//bool Date::operator >(const Date& date)
//{
//	if (_year > date._year)
//		return true;
//	else if (_year == date._year)
//	{
//		if (_month > date._month)
//			return true;
//		else if (_month == date._month)
//		{
//			if (_day > date._day)
//				return true;
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//	else
//		return false;
//}

bool  Date::operator>(const Date& date)
{
	if ((_year > date._year)
		|| ((_year == date._year) &&( _month > date._month) )
		|| ((_year == date._year) && (_month == date._month) && (_day > date._day)))
	{
		return true;
	}
	else
		return false;
}

bool Date::operator<(const Date& date)
{
	if ((_year < date._year)
		|| ((_year == date._year) && (_month < date._month))
		|| ((_year == date._year) && (_month == date._month) || (_day < date._day)))
		return true;
	else
		return false;
}

bool Date::operator==(const Date& date)
{
	return ((_year == date._year) && (_month == date._month) && (_day == date._day));
}

bool Date::operator!=(const Date& date)
{
	//return ((_year != date._year) || (_month != date._month) || (_day != date._day));
	return !(*this == date);
}

bool Date::operator>=(const Date& date)
{
	if ((*this) < date)
		return false;
	else
		return true;
}

bool Date::operator<=(const Date& date)
{
	if ((*this) > date)
		return false;
	else
		return true;
}