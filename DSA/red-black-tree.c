#include <stdio.h>
#include <stdlib.h>

//BST NODE
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//create a new node
Node* CreateNode(int data)
{
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->left= newNode->right NULL;
	return newNode;

}

//BINARY SEARCH TREE INSERTION
Node* insert(Node *root, int data)
{
	createNode(data);
	if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>roo->data)
		root->right=insert(root->right,data);

	return root;

}

//Inorddr traberse for checking
void inorder(Node* root)
{
	if(!root)return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
	
}
//driver

