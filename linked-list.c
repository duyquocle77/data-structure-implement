#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *pNext;
} Node;

typedef struct list{
	Node* pHead;
	Node* pTail;
} SList;

void InitSLL(SList &list) {
	list.pHead = list.pTail = NULL;
}

Node* CreatNode(int value) /* return address of new node */
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if (temp == NULL)
	{
		printf("Warning: Heap overflow !!!");
		return NULL;
	}
	temp->data = value;
	temp->pNext = NULL;
	return temp;
}

void preInsert(SList &list, Node* p) /* inserts a new item at the top of the list */
{
	if (list.pHead = NULL)
	{
		list.pHead = list.pTail = p;
	}
	else
	{
		p.pNext = list.pHead;
		list.pHead = p;
	}
}

Node* orderInsert(Node*, int)  /* inserts a new element in order, according to a key field */
{

}

void postInsert(SList& list, Node* p)     /* inserts a new item at the end of the list */
{
	if (list.pHead = NULL)
	{
		list.pHead = list.pTail = p;
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
} 

Node* findNode(Node*, int); /* find a node in the list */

Node* deleteNode(Node*, int); /* deletes a node corresponding to the inserted key */

Node* deleteList(Node*); /* deletes a list */

void printList(SList list) /* prints all the nodes in the list */
{ 
	Node* i = list.pHead;
	printf("Singly Linked-list:\n");
	while (i != NULL)
	{
		printf("%d ", i->data);
		i = i->pNext;
	}
}

void MergeSort(Node**); /* sorting algorithm */

Node* Merge(Node*, Node*); /* merges two sorted linked lists */

void Split(Node*, Node**, Node**); /* split the nodes of the list into two sublists */

int countNodes(Node*); /* returns the number of nodes in the list */

void main(void) {
	pHead = NULL;

}
