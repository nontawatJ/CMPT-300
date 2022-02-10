#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct nodeStruct* List_createNode(int item)
{
	struct nodeStruct* node = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
	if (node == NULL)
	{
		printf("error");
		exit(0);
	}
	node->item = item;
	node->next = NULL;
	return node;
}
void List_insertHead (struct nodeStruct** headRef,struct nodeStruct *node)
{
	if (*headRef == NULL)
	{
		*headRef = node;
		return;
	}
	node->next = *headRef;
	*headRef = node;
}
void List_insertTail (struct nodeStruct** headRef,struct nodeStruct *node)
{
	if (*headRef == NULL)
	{
		*headRef = node;
		return;
	}
	struct nodeStruct* current = *headRef;
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = node;
}
int List_countNodes (struct nodeStruct* head)
{
	struct nodeStruct* current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}
struct nodeStruct* List_findNode(struct nodeStruct *head,int item)
{
	struct nodeStruct* current = head;
	while (current != NULL)
	{
		if (current->item == item)
			return current;
		current=current->next;
	}
	return NULL;
}
void List_deleteNode (struct nodeStruct** headRef,struct nodeStruct* node)
{
	struct nodeStruct* current = *headRef;
	while (current->next != node)
	{
		current = current->next;
	}
	struct nodeStruct* prev = current;
	current = current->next;
	prev->next = current->next;
	free(current);
}
void List_swap(struct nodeStruct* a,struct nodeStruct* b)
{
	int temp = a->item;
	a->item = b->item;
	b->item = temp;
}
void List_sort (struct nodeStruct **headRef)
{
	int count = List_countNodes(*headRef);
	struct nodeStruct* current;
	struct nodeStruct* temp = NULL;
	if (*headRef == NULL)
		return;
	int comp;
	while(comp)
	{
		comp = 0;
		current = *headRef;
		while (current->next != temp)
		{
			if (current->item > current->next->item)
			{
				List_swap(current,current->next);
				comp = 1;
			}
			current = current->next;

		}
		temp = current;
	}
}

void print_list(struct nodeStruct *head)
{
	printf("\nprint Linked List:\n");
	struct nodeStruct* current = head;
	while (current != NULL)
	{
		printf("%d ",current->item);
		current = current->next;
	}
	printf("\n");
}

