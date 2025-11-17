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
	newNode->left= newNode->right= NULL;
	return newNode;

}

//BINARY SEARCH TREE INSERTION
Node* insert(Node *root, int data)
{
	CreateNode(data);
	if(data<root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
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




//I NEED TO ADD THE RED-BLACK NODE STRUCT + CREATENODE()
typedef enum {RED, BLACK} Color;

typedef struct RBNode 
{
	int data;
	Color color;
	struct RBNode *left, *right, *parent;
}RBNode;

RBNode* createNode(int data)

{
	RBNode* node= (RBNode*)malloc(sizeof(RBNode));
	node->data = data;
	node->color= RED; //new nodes start with red as default
	int count;
	node->left=node->right=node->parent=NULL;
	return node;
}


RBNode* bstInsert(RBNode* root, RBNode* node)
{
	if (root == NULL)
		return node;

	if(node->data < root->data)
	{
		root->left=bstInsert(root->left, node);
		root->left->parent =root;
	}

	else if(node->data > root->data)
	{
		root->right=bstInsert(root->right, node);
		root->right->parent=root;
	}
	//if equal, ignore
	else 
		root->count++;

	return root;
}






//driver
int main()
{
	
	return 0;
}
