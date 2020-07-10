/*

	Binary Search Tree
	AVL Tree

*/


#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>


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

class AVL_Node
{
public:
	int m_data;
	AVL_Node* left;
	AVL_Node* right;
 
	AVL_Node();
	
	int height;
	int Height(AVL_Node *root);
	AVL_Node* SingleRotateLeft(AVL_Node *X);
	AVL_Node* SingleRotateRight(AVL_Node *W);
	AVL_Node* DoubleRotatewithLeft(AVL_Node *Z);
	AVL_Node* DoubleRotatewithRight(AVL_Node *X);
	AVL_Node* Insert(AVL_Node *root, int data);
	void Find(AVL_Node *root, int data);
};


AVL_Node :: AVL_Node()
{
	m_data = 0;
	left = NULL;
	right = NULL;
}


int	AVL_Node::Height(AVL_Node *root){
	if (!root) return -1;
	else return root->height;
}

AVL_Node* AVL_Node::SingleRotateLeft(AVL_Node *X){
	AVL_Node *W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W;
}

AVL_Node* AVL_Node::SingleRotateRight(AVL_Node *W){
	AVL_Node *X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->right), Height(W->left)) + 1;
	X->height = max(Height(X->right), W->height) + 1;
	return X;
}

AVL_Node* AVL_Node::DoubleRotatewithLeft(AVL_Node *Z){
	Z->left = SingleRotateRight(Z->left);
	return  SingleRotateLeft(Z);
}

AVL_Node* AVL_Node::DoubleRotatewithRight(AVL_Node *X){
	X->right = SingleRotateLeft(X->right);
	return  SingleRotateRight(X);
}


AVL_Node* AVL_Node::Insert(AVL_Node *root, int data){
	if (!root) {
		root = new AVL_Node[sizeof(AVL_Node)];
		if (!root) {
			cout << "Memory Error" << endl;
			return root;
		}
		else{
			root->m_data = data;
			root->height = 0;
			root->left = root->right = NULL;
		}
	}
	else if (data < root->m_data){
		root->left = Insert(root->left, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (data < root->left->m_data)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	else if (data > root->m_data){
		root->right = Insert(root->right, data);
		if ((Height(root->right) - Height(root->left)) == 2) {
			if (data > root->right->m_data)
				root = SingleRotateRight(root);
			else root = DoubleRotatewithRight(root);
		}
	}
	root->height = max(Height(root->left), Height(root->right)) + 1;
	return root;
}

void AVL_Node::Find(AVL_Node *root, int data) {
	if (root == NULL)
		return;
	if (data < root->m_data)
		return Find(root->left, data);
	else if (data > root->m_data)
		return Find(root->right, data);
	else
	{
		//cout << data << endl;
		return;
	}
}










class BST_Node
{
public:
	int m_data;
	BST_Node* left;
	BST_Node* right;
 
	BST_Node();
	void insert(int data);
	void find(int data);
 
};

BST_Node :: BST_Node()
{
	m_data = NULL;
	left = NULL;
	right = NULL;
}

void BST_Node :: insert(int data)
{
	if(m_data == NULL)
	{
		m_data = data;
		return;
	}
	else 
	{
		if(data < m_data) // 현재 노드의 데이터 보다 작을때
		{
			if(left == NULL)
			{
				BST_Node* newnode = new BST_Node;
				left = newnode;
				left->m_data = data;
				return;
			}
			else
			{
				left->insert(data);
				return;
			}
		}
		if(data > m_data)  // 현재 노드의 데이터 보다 클때
		{
			if(right == NULL)
			{
				BST_Node* newnode = new BST_Node;
				right = newnode;
				right->m_data = data;
				return;
			}
			else
			{
				right->insert(data);
				return;
			}
		}
		if(data == m_data)  // 현재 노드의 데이터와 같을때
		{
			insert((((long)rand() << 15) | rand()) % 1000000 + 1);
			return;
		}
	}
}



void BST_Node :: find(int data)
{
	if(m_data == data)
	{
		return;
	}
	else 
	{
		if(data < m_data)
		{
			if (left == NULL)
				return;
			left->find(data);
			return;
		}		
		if(data > m_data)
		{
			if (right == NULL)
				return;
			right->find(data);
			return;
		}
	}
}


void main(){
	double d0, d1;
	srand(time(0));
	
	cout << "< BST > " << endl;

	BST_Node root;

	d0 = cputimer();
	for (int i = 0; i < 1000000; i++)
	{
		root.insert( (((long)rand() << 15) | rand()) % 1000000 + 1 );
	}
	printf("insert 완료\n");

	for (int i = 0; i < 1000000; i++)
	{
		root.find( (((long)rand() << 15) | rand()) % 1000000 + 1 );
	}
	printf("find 완료\n");

	d1 = cputimer();

	cout << "(1) Elapsed Time: " << d1 - d0 << endl;




	BST_Node root2;

	d0 = cputimer();
	for(int i = 1; i <= 3000; i++)
		root2.insert( i );
	printf("insert 완료\n");

	for(int i = 1; i <= 3000; i++)
		root2.find( (rand() % 3000)+1 );
	printf("find 완료\n");

	d1 = cputimer();

	cout << "(2) Elapsed Time: " << d1 - d0 << endl;


	cout << endl;
	cout << endl;

	cout << "< AVL > " << endl;
	
	AVL_Node* root3;
	root3 = NULL;

	d0 = cputimer();
	for (int i = 0; i<100000; i++) {
		root3 = root3->Insert(root3, (((long)rand() << 15) | rand()) % 1000000 + 1);
	}
	printf("insert 완료\n");
	for (int i = 0; i<100000; i++) {
		root3->Find(root3, (((long)rand() << 15) | rand()) % 1000000 + 1);
	}
	printf("find 완료\n");
	d1 = cputimer();

	cout << "(1) Elapsed Time: " << d1 - d0 << endl;


	AVL_Node* root4;
	root4 = NULL;

	d0 = cputimer();
	for (int i = 0; i<4000; i++) {
		root4 = root4->Insert(root4, (rand() % 4000) + 1);
	}
	printf("insert 완료\n");
	for (int i = 0; i<4000; i++) {
		root4->Find(root4, (rand() % 4000) + 1);
	}
	printf("find 완료\n");
	d1 = cputimer();

	cout << "(2) Elapsed Time: " << d1 - d0 << endl;

}