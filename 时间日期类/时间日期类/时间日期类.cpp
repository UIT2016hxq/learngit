// 时间日期类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class time
{
public:
	int hour;
	int minute;
	int second;
	void show_time();
};

class date 
{	
public:
	int year;
	int month;
	int day;
	void show_date();
};

class date_time:public date,public time
{
public:
	void ShowDate_Time();
};
int main()
{
	time a; date b; date_time c;
	int h=23, m=59, s=59, y=2018, mon=3, d=20;
	a.hour = h; a.minute = m; a.second = s;
	a.show_time();
	b.year = y; b.month = mon; b.day = d;
	b.show_date();
	c.year = y; c.month = mon; c.day = d;
	c.hour = h; c.minute = m; c.second = s;
	c.ShowDate_Time();
	system("pause");
    return 0;
}
void time::show_time()
{
	cout << hour << ':' << minute << ':' << second<<endl;
}
void date::show_date()
{
	cout << year << "年" << month << "月" << day << "日" <<endl;
}
void date_time::ShowDate_Time()
{
	show_date();
	cout << ' ';
	show_time();
	cout << endl;
}