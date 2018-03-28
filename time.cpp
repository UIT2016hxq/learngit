// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Dayofyear
{
public:
	void input();
	void output();
	void set(int newmouth, int newday);
	void set(int newmouth);
	int  getmonth();
	int  getday();
private:
	int month;
	int day;
};

void Dayofyear::set(int newmonth, int newday)
{
	if ((newmonth>= 1) && (newmonth <= 12))
		month = newmonth;
	else
	{
		cout << "错误！";
		exit(1);
	}
	if ((newday >= 1) && (newday <= 31))
		day = newday;
	else
	{
		cout << "错误！";
		exit(1);
	}
}

void Dayofyear::set(int newmonth)
{
	if ((newmonth >= 1) && (newmonth <= 12))
		month = newmonth;
	else
	{
		cout << "错误！";
		exit(1);
	}
	day = 1;
}

int Dayofyear::getmonth()
{
	return month;
}

int Dayofyear::getday()
{
	return day;
}

void Dayofyear::input()
{
	cout << "输入月份：";
	cin >> month;
	cout << "输入日期：";
	cin >> day;
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
	{
		cout << "错误！";
		exit(1);
	}
}

void Dayofyear::output()
{
	switch (month)
	{
	case 1:
		cout << "Journey"; break;
	case 2:
		cout << "Februday"; break;
	case 3:
		cout << "March"; break;
	case 4:
		cout << "April"; break;
	case 5:
		cout << "May"; break;
	case 6:
		cout << "June"; break;
	case 7:
		cout << "July"; break;
	case 8:
		cout << "August"; break;
	case 9:
		cout << "September"; break;
	case 10:
		cout << "October"; break;
	case 11:
		cout << "November"; break;
	case 12:
		cout << "December"; break;
	default:
		cout << "错误！";
	}
	cout << "day";
}
int main()
{
	Dayofyear today;
	cout << "输入日期；"<<endl;
	today.input();
	cout << "日期是：";
	today.output();
	cout << endl;
    return 0;
}