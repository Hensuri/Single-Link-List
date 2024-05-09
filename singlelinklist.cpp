#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int value;
	struct Node *next;
}*head = NULL, *tail = NULL;


struct Node *createNode(int value)
{
	struct Node *newEle = (Node*) malloc (sizeof(Node));
	
	newEle->value = value;
	newEle->next = NULL;
	
	return newEle;
}

void pushHead(int value)
{
	struct Node *newNode = createNode(value);
	
	if(head == NULL)
	{
		head = tail = newNode;
		return;
	}
	
	newNode->next = head;
	head = newNode;
}


void pushTail(int value)
{
	struct Node *newNode = createNode(value);
	
	if(tail == NULL)
	{
		head = tail = newNode;
		return;
	}
	
	tail->next = newNode;
	tail = newNode;
}

void pushMid(int value)
{
	struct Node *newNode = createNode(value);
	
	if(head == NULL)
	{
		head = tail = newNode;
		return;
	}
	else if(head->value >= value)
	{
		pushHead(value);
		return;
	}
	else if(tail->value <= value)
	{
		pushTail(value);
		return; 
	}
	
	struct Node *curr = head;
	struct Node *prev = NULL;
	
	while(curr->next != NULL && curr->value < value)
	{
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = newNode;
	newNode->next = curr;
}

void popHead()
{
	
	if(head == NULL)
	{
		return;
	}
	if(head == tail)
	{
		free(head);
		head = tail = NULL;
		return;
	}
	struct Node *temp = head;
	
	head = head->next;
	free(temp);
}

void popTail()
{
	if(head == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		free(head);
		head = tail = NULL;
		return;
	}
	
	struct Node *curr = head;
	
	while(curr->next != tail)
	{
		curr = curr->next;
	}
	
	struct Node *temp = tail;
	tail = curr;
	tail->next = NULL;
	
	free(temp);
}

void popMid(int value)
{
	if(head == NULL)
	{
		return;
	}
	else if(head->value == value)
	{
		popHead();
	}
	else if(tail->value == value)
	{
		popTail();
	}
	
	struct Node *curr = head;
	struct Node *prev = NULL;
	
	while(curr->next != NULL && curr->value != value)
	{
		prev = curr;
		curr = curr->next;
	}
	
	if(curr == NULL)
	{
		return;
	}
	else
	{
		prev->next = curr->next;
		free(curr);
	}
}

void popByIndex(int index)
{
	if(head == NULL)
	{
		return;
	}
	else if(index == 1)
	{
		popHead();
		return;
	}
	
	int i = 1;
	
	struct Node *curr = head;
	struct Node *prev = NULL;
	
	
	
	while(i != index && i < index)
	{
		prev = curr;
		curr = curr->next;
		i++;

	}
	
	if(curr == NULL)
	{
		return;
	}
	else
	{
		prev->next = curr->next;
		free(curr);
	}
}

void printAll()
{
	struct Node *current = head;
	
	while(current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	
	printf("\n");
}

int main()
{
	pushMid(10);
	printAll();
	
	pushMid(10);
	printAll();
	
	pushMid(100);
	printAll();
	
	pushMid(20);
	printAll();
	
	pushMid(30);
	printAll();
	
	pushMid(500);
	printAll();
	
	popByIndex(4);
//	printAll();
}

