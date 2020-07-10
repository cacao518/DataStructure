/*
	Single Linked List
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
};

class List
{
	public:
		Node* head;
		int numOfData;

		void insert(int data);
		int search(int r);
		void del(int r);
		List();
};

List :: List()
{
	head = NULL;
	numOfData = 0;
}

void List :: insert(int data)
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
		head = newnode;
	}

	numOfData++;
}


int List :: search(int r)
{
	Node* temp = head;
	for(int i = 0; i<r; i++)
	{
		temp = temp->next;
	}
	return temp->m_data;
}

void List :: del(int r)
{
	Node* temp = head->next;
	Node* prev = head;
	for(int i = 0; i<r;  i++)
	{	
		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;
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
	List list;
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