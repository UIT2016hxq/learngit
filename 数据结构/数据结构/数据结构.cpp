// 数据结构.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
const int MaxListSize = 20;
using namespace std;
class SeqList											//线性表类
{
public:
	SeqList(int a[], int);								//线性表构造函数
	~SeqList();											//线性表析构函数
	void Insert1(int i, int x);							//线性表元素插入
	void Delete1(int i);								//线性表元素删除
	int GetNode1(int i);								//查找线性表元素
	void ShowList();									//输出线性表
private:
	int data[MaxListSize];
	int length;
};

SeqList::~SeqList(){}									//销毁线性表

void SeqList::ShowList()								//输出线性表
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << " ";
		cout << endl;
	}
}

SeqList::SeqList(int a[], int n)							//线性表构造函数
{
	length = n;
	for (int i = 0; i < length; i++)
		data[i] = a[i];
}

void SeqList::Insert1(int i, int x)							//增加线性表元素
{
	if (i<1 || i>length - 1)
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	for (int j = length - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = x;
	length++;
}

void SeqList::Delete1(int i)									//删除线性表元素
{
	if (i<1 || i>length - 1)
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	for (int j = i; j <= length - 1; j++)
		data[j - 1] = data[j];
	length--;
}

int SeqList::GetNode1(int i)									//查找线性表元素
{
	if (i<1 || i>length - 1)
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	else
		return data[i - 1];
}

struct node														//链表节点
{
	int data;
	node *next;
};

class LinkList												//链表类
{
public:
	LinkList(int a[], int n);
	~LinkList();
	int Length();											//求链表长度
	void Insert2(int i, int x);								//链表元素插入
	void Delete2(int i);									//链表元素删除
	int GetNode2(int i);									//查找链表元素
	void ShowList2();										//输出链表
private:
	node * head;
};

LinkList::LinkList(int a[], int n)						//链表构造函数
{
	node *p;
	head = new node;
	head->next = NULL;
	for (int i = 0; i < n; i++)
	{
		p = new node;
		p->data = a[i];
		p->next = head->next;
		head->next = p;
	}
}

LinkList::~LinkList()									//销毁链表
{
	node *p, *q;
	p = head;
	while (p)
	{
		q = p;
		p = p->next;
		delete p;
	}
}

int LinkList::Length()									//求链表长度
{
	int n = 0;
	node *p;
	p = head;
	while (p->next)
	{
		p = p->next;
		n++;
	}
	return n;
}

int LinkList::GetNode2(int i)							//查找链表中目标结点
{
	if (i<1 || i>Length())
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	else
	{
		int j = 1;
		node *p;
		p = head->next;
		while (j != i)
		{
			p = p->next;
			j++;
		}
		return p->data;
	}
}

void LinkList::Insert2(int i, int x)						//增加结点
{
	if (i<1 || i>Length()-1)
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	else
	{
		int j = 0;
		node *p, *q;
		p = head;
		while (p->next && j < i - 1)
		{
			p = p->next;
			j++;
		}
		q = new node;
		q->data = x;
		q->next = p->next;
		p->next = q;
	}
}

void LinkList::Delete2(int i)								//删除结点
{
	if (i<1 || i>Length() - 1)
	{
		cout << "非法位置，终止运行！" << endl;
		exit(1);
	}
	else
	{
		int j = 0;
		node *p, *q;
		p = head;
		while (i > 0 && p->next)
		{
			if (j == i - 1)
				break;
			p = p->next;
			j++;
		}
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

void LinkList::ShowList2()								//输出链表
{
	node *p;
	p = head;
	while (p->next)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}

class SeqStack											//栈类
{
public:
	SeqStack(int a[], int n);							//栈构造函数，初始化栈
	~SeqStack();										//栈析构函数，销毁栈
	int IsFull();										//判断栈是否满
	int IsEmpty();										//判断栈是否空
	void Push(int x);									//进栈
	void Pop(int &x);									//退栈
private:
	int data[MaxListSize];
	int top;
};

SeqStack::SeqStack(int a[], int n)
{
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	top = n - 1;
}

SeqStack::~SeqStack()
{
	top = -1;
}

int SeqStack::IsFull()
{
	return (top == MaxListSize - 1);
}

int SeqStack::IsEmpty()
{
	return (top == -1);
}

void SeqStack::Pop(int &x)
{
	if (IsEmpty())
	{
		cout << "栈空，终止运行！" << endl;
		exit(1);
	}
	x = data[top];
	top--;
}

void SeqStack::Push(int x)
{
	if (IsFull())
	{
		cout << "栈满，终止运行！" << endl;
		exit(1);
	}
	top++;
	data[top] = x;
}
int main()
{

    return 0;
}