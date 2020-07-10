/*

< Double Dynamic Array Stack >

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

class DDyStack
{
public:
	int *m_stack;
	int m_size;
	int m_top;

	DDyStack();
	void Push(int data);
	void Pop();

};

DDyStack::DDyStack()
	:m_top(-1), m_size(1)
{
	m_stack = (int *)malloc(m_size * sizeof(int));

}

void DDyStack::Push(int data)
{
	if ((m_top + 1) == m_size)
	{
		m_stack = (int *)realloc(m_stack, (m_size * 2) * sizeof(int));
		// realloc의 비용이 비싸기 때문에 크기를 2배씩 커지게 하면 탐색속도가 빨라지는 장점이 있다.
		m_size *= 2;
	}
	m_stack[++m_top] = data;
}

void DDyStack::Pop()
{
	m_top--;
}

void main(){
	double d0, d1;

	cout << "<Double Dynamic Array Stack> " << endl;

	cout << "#1 " << endl;

	DDyStack ddystack1;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
		ddystack1.Push(i);

	for (int i = 0; i < 100000; i++)
		ddystack1.Pop();

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack1.m_stack);

	DDyStack ddystack2;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
		ddystack2.Push(i);

	for (int i = 0; i < 1000000; i++)
		ddystack2.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack2.m_stack);

	DDyStack ddystack3;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
		ddystack3.Push(i);

	for (int i = 0; i < 10000000; i++)
		ddystack3.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack3.m_stack);

	///////////////////////////////////////////////////////////////////////////////

	cout << "#2 " << endl;


	DDyStack ddystack4;
	d0 = cputimer();

	for (int i = 0; i < 100000; i++)
	{
		ddystack4.Push(i);
		ddystack4.Pop();
	}

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack4.m_stack);

	DDyStack ddystack5;
	d0 = cputimer();

	for (int i = 0; i < 1000000; i++)
	{
		ddystack5.Push(i);
		ddystack5.Pop();
	}

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack5.m_stack);

	DDyStack ddystack6;
	d0 = cputimer();

	for (int i = 0; i < 10000000; i++)
	{
		ddystack6.Push(i);
		ddystack6.Pop();
	}

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack6.m_stack);


	///////////////////////////////////////////////////////////////////////////////


	cout << "#3 " << endl;


	DDyStack ddystack7;
	d0 = cputimer();

	for (int i = 0; i < 20; i++)
	{
		for (int i = 0; i < 10000; i++)
			ddystack7.Push(i);
		for (int i = 0; i < 5000; i++)
			ddystack7.Pop();
	}
	for (int i = 0; i < 100000; i++)
		ddystack7.Pop();

	d1 = cputimer();

	cout << "(a) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack7.m_stack);

	DDyStack ddystack8;
	d0 = cputimer();

	for (int i = 0; i < 200; i++)
	{
		for (int i = 0; i < 10000; i++)
			ddystack8.Push(i);
		for (int i = 0; i < 5000; i++)
			ddystack8.Pop();
	}
	for (int i = 0; i < 1000000; i++)
		ddystack8.Pop();

	d1 = cputimer();

	cout << "(b) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack8.m_stack);

	DDyStack ddystack9;
	d0 = cputimer();

	for (int i = 0; i < 2000; i++)
	{
		for (int i = 0; i < 10000; i++)
			ddystack9.Push(i);
		for (int i = 0; i < 5000; i++)
			ddystack9.Pop();
	}
	for (int i = 0; i < 10000000; i++)
		ddystack9.Pop();

	d1 = cputimer();

	cout << "(c) Elapsed Time: " << d1 - d0 << endl;
	free(ddystack9.m_stack);
	
}