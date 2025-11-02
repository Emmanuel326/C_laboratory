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
////prev stores the previous node
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

//(B) INSERT AT THE FRONT

void insertFront(Node **head, int data)
{
	Node *newNode=createNode(data);
	newNode->next=*head;
	if(!*head)
		(*head)->prev =newNode;
	*hea=newNode;
}

//visual
//insert 5 at front of 10<->20<->30
//before:NULL<-[10]<->[20]<->[30]
//AFTER:NULL<-[5]<->[10]<->[20]<->[30]

//(C)insert at the end
void insertEnd(Node**head, int data)
{
	Node *newNode=createNode(data);
	if(*head==NULL)
	{
		*head=newNode;
		return;
	}
	Node *temp=*head;
	while(temp->next !=NULL)
		temp=tenp->next;
	temp->next=newNode;
	newNode->prev=temp;
}


