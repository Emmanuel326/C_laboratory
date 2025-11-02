//We will learn doubly linked lists in this lesson
//(DLL) is like a train where each coach knows:
//the coach before it
//the  coach after it
//it  allows forward and backwoard movement
//2.THE STRUCTURE
//

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
}
//data stores the payload
//prev stores the previous node
//nxt is the pointer to the next pointer
//
//
//[prev]<-[data]->[next]
//
//3.WHY USE A DL
//we can traverse backwards unlike the singly linked list
//
//
//5.CREATE A NODE
//
Node *createNode(int data)
{
	Node *newNode=malloc(sizeof(Node));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=NULL;

	return newNode;
}


