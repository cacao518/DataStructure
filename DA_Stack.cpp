/*

< Dynamic Array Stack >

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

class DyStack
{
	public:
		int *m_stack;
		int m_size;
		int m_top;

		DyStack();
		void Push(int data);
		void Pop();

};

DyStack::DyStack()
:m_top(-1), m_size(1)
{
	m_stack = (int *)malloc(m_size * sizeof(int));

}

void DyStack::Push(int data)
{
	if ((m_top + 1) == m_size)
	{
		m_stack = (int *)realloc(m_stack, (m_size + 1) * sizeof(int));
		m_size++;
	}
	m_stack[++m_top] = data;
	
}

void DyStack::Pop()
{
	m_top--;
}

void main(){
	double d0, d1;

	cout << "<Dynamic Array Stack> " << endl;

	cout << "#1 " << endl;

	DyStack dystack1;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
		dystack1.Push(i);
	
	for (int i = 0; i < 100000; i++)
		dystack1.Pop();
	
	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(dystack1.m_stack);

	DyStack dystack2;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
		dystack2.Push(i);

	for (int i = 0; i < 1000000; i++)
		dystack2.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(dystack2.m_stack);

	DyStack dystack3;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
		dystack3.Push(i);

	for (int i = 0; i < 10000000; i++)
		dystack3.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(dystack3.m_stack);
///////////////////////////////////////////////////////////////////////////////
	
	
	
	cout << "#2 " << endl;
	
	DyStack dystack4;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
	{
		dystack4.Push(i);
		dystack4.Pop();
	}

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(dystack4.m_stack);

	
	DyStack dystack5;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
	{
		dystack5.Push(i);
		dystack5.Pop();
	}

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(dystack5.m_stack);

	
	DyStack dystack6;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
	{
		dystack6.Push(i);
		dystack6.Pop();
	}

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(dystack6.m_stack);

	///////////////////////////////////////////////////////////////////////////////

	cout << "#3 " << endl;

	DyStack dystack7;
	d0 = cputimer();


	for (int i = 0; i < 20; i++)
	{
		for (int i = 0; i < 10000; i++)
			dystack7.Push(i);
		for (int i = 0; i < 5000; i++)
			dystack7.Pop();
	}
	for (int i = 0; i < 100000; i++)
		dystack7.Pop();

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(dystack7.m_stack);


	DyStack dystack8;
	d0 = cputimer();

	for (int i = 0; i < 200; i++)
	{
		for (int i = 0; i < 10000; i++)
			dystack8.Push(i);
		for (int i = 0; i < 5000; i++)
			dystack8.Pop();
	}
	for (int i = 0; i < 1000000; i++)
		dystack8.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(dystack8.m_stack);


	DyStack dystack9;
	d0 = cputimer();

	for (int i = 0; i < 2000; i++)
	{
		for (int i = 0; i < 10000; i++)
			dystack9.Push(i);
		for (int i = 0; i < 5000; i++)
			dystack9.Pop();
	}
	for (int i = 0; i < 10000000; i++)
		dystack9.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(dystack9.m_stack);
}