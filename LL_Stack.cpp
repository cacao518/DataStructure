/*

       < Linked List Stack >

*/


#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#define WIN32_LEAN_AND_MEAN

using namespace std;

double cputimer()
{
	FILETIME createTime;
	FILETIME exitTime;
	FILETIME kernelTime;
	FILETIME userTime;
	SYSTEMTIME userSystemTime;

	if (GetProcessTimes(GetCurrentProcess(), &createTime, &exitTime, &kernelTime, &userTime) != -1){
		if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1){
			return (double)userSystemTime.wHour * 3600.0 * 1000.0 +
				(double)userSystemTime.wMinute * 60.0 * 1000.0 +
				(double)userSystemTime.wSecond * 1000.0 +
				(double)userSystemTime.wMilliseconds;
		}
	}
}
class Node
{
public:
	int m_data;
	Node* next;
};


class LStack
{
public:
	Node* head;
	int numOfData;

	LStack();

	void Push(int data);
	void Pop();

};

LStack::LStack()
{
	head = NULL;
	numOfData = 0;
}

void LStack::Push(int data)
{
	if (head == NULL)
	{
		Node* newnode = new Node;
		newnode->m_data = data;
		newnode->next = NULL;
		head = newnode;
	}
	else
	{
		Node* newnode = new Node;
		newnode->m_data = data;
		newnode->next = head;
		head = newnode;
	}

	numOfData++;
}

void LStack::Pop()
{
	Node* temp = head;

	head = head->next;
	
	delete temp;
	numOfData--;
}

void main(){
	double d0, d1;

	cout << "<Linked List Stack> " << endl;

	cout << "#1 " << endl;
	LStack lstack1;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
		lstack1.Push(i);

	for (int i = 0; i < 100000; i++)
		lstack1.Pop();

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack2;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
		lstack2.Push(i);

	for (int i = 0; i < 1000000; i++)
		lstack2.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack3;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
		lstack3.Push(i);

	for (int i = 0; i < 10000000; i++)
		lstack3.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;


	cout << "#2 " << endl;
	LStack lstack4;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
	{
		lstack4.Push(i);
		lstack4.Pop();
	}


	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack5;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
	{
		lstack5.Push(i);
		lstack5.Pop();
	}

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack6;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
	{
		lstack6.Push(i);
		lstack6.Pop();
	}

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;

	cout << "#3 " << endl;
	LStack lstack7;
	d0 = cputimer();

	for (int i = 0; i < 20; i++)
	{
		for (int i = 0; i < 10000; i++)
			lstack7.Push(i);
		for (int i = 0; i < 5000; i++)
			lstack7.Pop();
	}
	for (int i = 0; i < 100000; i++)
		lstack7.Pop();


	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack8;
	d0 = cputimer();

	for (int i = 0; i < 200; i++)
	{
		for (int i = 0; i < 10000; i++)
			lstack8.Push(i);
		for (int i = 0; i < 5000; i++)
			lstack8.Pop();
	}
	for (int i = 0; i < 1000000; i++)
		lstack8.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;

	LStack lstack9;
	d0 = cputimer();

	for (int i = 0; i < 2000; i++)
	{
		for (int i = 0; i < 10000; i++)
			lstack9.Push(i);
		for (int i = 0; i < 5000; i++)
			lstack9.Pop();
	}
	for (int i = 0; i < 10000000; i++)
		lstack9.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
}