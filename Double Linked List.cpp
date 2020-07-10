/*
	Double Linked List

*/

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
 
using namespace std;

#define WIN32_LEAN_AND_MEAN
 
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
	Node* before; 
};

class DList
{
	public:
		Node* head;
		int numOfData;

		void insert(int data);
		int search(int r);
		void del(int r);
		DList();
};

DList :: DList()
{
	head = NULL;
	numOfData = 0;
}

void DList :: insert(int data)
{
	if(head == NULL)
	{
		Node* newnode = new Node;
		newnode->m_data = data;
		newnode->next=NULL;
		head = newnode;
	}
	else
	{
		Node* newnode = new Node;
		newnode->m_data = data;
		newnode->next = head;
		head->before = newnode;
		head = newnode;
	}

	numOfData++;
}


int DList :: search(int r)
{
	Node* temp = head;
	for(int i = 0; i<r; i++)
	{
		temp = temp->next;
	}
	return temp->m_data;
}

void DList :: del(int r)
{
	Node* temp = head->next;
	Node* prev = head;
	Node* front = head->next->next;
	for(int i = 0; i<r;  i++)
	{	
		front = temp->next->next;
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	front->before = temp->before;

	delete temp;
	numOfData--;
}

void main(){
   double d0, d1;

   srand(time(0));
   d0 = cputimer();
   int arr[100000];
   for(int i = 0; i<100000; i++)
   {
	   arr[i] = i;
   }
   d1 = cputimer();

   printf("(1) Insertion\n");
   printf("- Array \n");
   printf("Elapsed Time: %lf\n\n", (d1 - d0));


	d0 = cputimer();
	DList list;
	for(int i = 0; i<100000; i++)
	{	
		list.insert( i );
	}
   d1 = cputimer();
 
   printf("- Linked List\n");
   printf("Elapsed Time: %lf\n\n", (d1 - d0));

/////////////////////////////////////////////////////////////////////////
   d0 = cputimer();
   double sum = 0;

   for(int i = 0; i<=10000; i++)
   {
	   int r = rand() % 10000;
	   sum += arr[ r ];
   }
   d1 = cputimer();

   printf("(2) Random access for read\n");
   printf("- Array ( sum : %.lf )\n", sum);
   printf("Elapsed Time: %lf\n\n", (d1 - d0));

   d0 = cputimer();
   sum = 0;

   for(int i = 0; i<=10000; i++)
   {
	   int r = rand() % 10000;
	   sum += list.search( r );
   }
   d1 = cputimer();

   printf("- Linked List ( sum : %.lf )\n", sum);
   printf("Elapsed Time: %lf\n\n", (d1 - d0));

////////////////////////////////////////////////////////////////////////

  d0 = cputimer();

   for(int i = 0; i<=10000; i++)
   {
	   int r = rand() % 10000;
	  arr[ r ] = -1;
   }
   d1 = cputimer();

   printf("(3) Random access for deletion\n");
   printf("- Array \n");
   printf("Elapsed Time: %lf\n\n", (d1 - d0));


    d0 = cputimer();

   for(int i = 0; i<10000; i++)
   {
	   int r = rand() % (10000 - i);
	   list.del( r );
   }
   d1 = cputimer();

   printf("- Linked List \n");
   printf("Elapsed Time: %lf\n\n", (d1 - d0));


}