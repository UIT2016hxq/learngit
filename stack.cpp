// stack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define MAXSIZE 50;
class stack
{
public:
	int initstack(stack *s);
	int pop(stack *s, int *e);
	int push(stack *s, int e);
private:
	int *base;												//栈底指针
	int *top;												//栈顶指针
	int stacksize;
};

int stack::initstack(stack *s)								//初始化栈
{
	s->base = (int *)malloc(sizeof(int));
	if (!s->base)
		return 0;
	s->top = s->base;
	s->stacksize = MAXSIZE;
	return 1;
}

int stack::pop(stack *s, int *e)						    //出栈
{
	if (s->base == s->top)
		return 0;
	s->top--;
	*e = *(s->top);
	return 1;
}

int stack::push(stack *s, int e)						   //入栈
{
	/*if (s->top - s->base >= s->stacksize)
	{
		s->base=(int *)realloc(s->base,sizeof(int)*)
	}*/
	*(s->top) = e;
	s->top++;
	return 1;
}


int main()
{
	stack S;
	int e;
	int *E = &e;
	stack *s = &S;
	S.initstack(&S);
	S.pop(&S, &e);
	S.push(&S ,e);
    return 0;
}

