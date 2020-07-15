/*

	Trie

*/

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;

class Node
{
public:
	bool finish;
	Node* next[26];

	Node();
	void Insert(char* str);
	bool Find(char* str);
};

Node::Node()
{
	finish = false;
	for (int i = 0; i < 26; i++) next[i] = NULL;
};
void Node::Insert(char* str)
{
	if (*str == NULL)
	{
		finish = true;
		return;
	}

	int cur = *str - 'a'; // 첫번째 글자가 배열(포인터 char)의 시작주소
	if (next[cur] == NULL)
		next[cur] = new Node();

	next[cur]->Insert(str + 1);
}

bool Node::Find(char* str) 
{
	if (*str == NULL)
	{
		if (finish == true) 
			return true;

		return false;
	}
	int cur = *str - 'a'; 

	if (next[cur] == NULL)
		return false;
	
	return next[cur]->Find(str + 1);
}



void main() {

	Node* root = new Node;
	
	root->Insert((char*)"dog");
	root->Insert((char*)"doggy");
	root->Insert((char*)"rabbit");
	root->Insert((char*)"rubber");
	root->Insert((char*)"rub");
	root->Insert((char*)"love");
	root->Insert((char*)"low");
	
	cout << root->Find((char*)"dog") << endl;
	cout << root->Find((char*)"doggy") << endl;
	cout << root->Find((char*)"rabbit") << endl;
	cout << root->Find((char*)"rubber") << endl;
	cout << root->Find((char*)"rub") << endl;
	cout << root->Find((char*)"love") << endl;
	cout << root->Find((char*)"low") << endl;
	cout << root->Find((char*)"doge") << endl;

	return;
}