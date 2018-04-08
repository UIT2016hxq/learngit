// 计算器1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"




#include<stdio.h>
#include<iostream>
#include<string> 
using namespace std;
#pragma once
class cr
{
private:
	double *i;
	int j;
	char c;
	int k;
public:
	void judge1(double *i, int j, char c);
	void judge2(double *i, char *c, int j, int k);
};

void cr::judge1(double *i, int j, char c)//判断乘除
{
	float m;
	cin >> m;
	if (c == '*')
		i[j] = i[j] * m;
	else
		i[j] = i[j] / m;
}

void cr::judge2(double *i, char *c, int j, int k)//判断加减
{
	for (; j>0; j--, k--)
	{
		if (c[k] == '+')
			i[j - 1] = i[j - 1] + i[j];
		else
			i[j - 1] = i[j - 1] - i[j];
	}
}


int main()
{
	cr plan;
	int ic = 0, j = 0, k = 0;
	double count[3];
	char c[3];
	while (1)
	{
		if (ic == 0)
		{
			cin >> count[j++];//数据输入
			ic = 1;
		}
		if (ic == 1)
		{

			c[k++] = getchar();//符号输入
			if (c[k - 1] == '*' || c[k - 1] == '/')
			{
				plan.judge1(count, j - 1, c[k - 1]);
				k--;
				continue;
			}
			else if (c[k - 1] == '\n')
				break;
			ic = 0;
		}

	}
	plan.judge2(count, c, j - 1, k - 2);
	cout << count[0];
	return 0;
}