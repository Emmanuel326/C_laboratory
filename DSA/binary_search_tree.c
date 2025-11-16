 //The structure--"A Node is a box that holds data"
#include <stdio.h>
#include <stdlib.h>

//a node represents one element of the tree.
typedef struct TreeNode 
{
	int value;  //the actual data we store
	struct TreeNode *left_child;  //pointer to smaller values
	struct TreeNode *right_child;  //pointer to larger values
}TreeNode;

//create a new node-"Build a box"
TreeNode * create_node(int value)
{
	TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode)); 
	if(new_node==NULL)
	{
		perror("Malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node ->value =value;

	new_node ->left_child=NULL;


	new_node->right_child=NULL;

	return new_node;



}//wherever we need something we first create a box for it.
 //
 // 
 //idea before code
 //smaller values goes to left
 //larger values to right
 //if we need to place a value we go down he teee, compare. Go left until we find an empty spot insert a new box(node) tree
 //
 //ADD VALUES()-ADD VALUES TO THE TREE
 
//place a value into the tree at the correct spoyt
TreeNode * insert_value(TreeNode *root, int value)
{
	//if tree is empty create first node
	if(root==NULL)
	{
		return create_node(value);
	}
	//if smaller go left
	if(value < root -> value)
	{
		root->left_child=insert_value(root->left_child,value);
	}
	//if larger go right
	if(value > root->value)
	{
		root->right_child=insert_value(root->right_child, value);
	}
	//if equal do nothing. ignore duplicates
	else
	{
		//adda debug print 
		printf("Vale $d already exists\n", value);
	}
	return root;
	
}


//STEP 3. SEARCH A VALUE
//you look for a value by comparing
//if equal-found
//if smaller-search left
//if bigger -> search right
//if you hit NULL-> does not exist
//


//search or a value down the tree
TreeNode *search_value(TreeNode *root, int target)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(target==root->value)
	{
		return root; //found the box
	}
	if(target <root->value)
	{
		return search_value(root->left_child);

	}
	else
	{
		return search_value(root->right_child);
	}
}

//STEP 4. PRINT TREE(SORTED)
//inoder traversal prints values from smallest-largest

void print_in_order(TreeNode *root)
{
	if(root==NULL)
		return;
	
		
		print_in_order(root->left_child);
		printf("%d", root->value);
		print_in_order(root -> right_child);

	
}


//helper function

TreeNode *find_min(TreeNode *node)
{
	while(node->left_child != NULL)
	{
		node=node->left_child;

	}
	return node;
}
//BST DELETE FUNCTION
TreeNode* delete_value(TreeNode *root, int target)
{
	if(root==NULL)
		return NULL;

	//step 1.searchforthenode...
	if(target<root->value)
	{
		root->left_child=delte_value(root->left_child, target);

	}
	else if(target > root->value)
	{
		root->right_child=delete_value(root->right_child,target);

			
	}
	else
	{
		//...found the node...//
		//case 1: no child(leaf)
		if(root->left_cild==NULL && root->right_child==NULL)
		{
			free(root);
		return NULL;

	}

	//case 2. one child only//
	if(root->left_child==NULL)
	{
		TreeNode* temp=root->left_child;
		free(root);
		return temp;
	}

	//case 3: 2 children
	TreeNode *successor=find_min(root->right_child);
	root->value = successor->value;
	root->right_child=delete_value(root->right_child,successor->value);

	}
	return root;
}
