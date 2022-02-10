#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

static _Bool doSinglePassOnSort(struct nodeStruct **headRef);
static void swapElements(struct nodeStruct **previous, struct nodeStruct *nodeA, struct nodeStruct *b);

struct nodeStruct* List_createNode(void* ptr)
{
	struct nodeStruct *pNode = malloc(sizeof(struct nodeStruct));
	if (pNode != NULL) {
		pNode->ptr = ptr;
	}
	pNode->next = NULL;
	return pNode;
}
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node)
{
	node->next = *headRef;
	*headRef = node;
}
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node)
{
	node->next = NULL;
	if (*headRef == NULL) 
	{
		*headRef = node;
	}
	else {
		struct nodeStruct *current = *headRef;
		while (current->next != NULL) 
		{
			current = current->next;
		}
		current->next = node;
	}
}
int List_countNodes (struct nodeStruct *head)
{
	int count = 0;
	struct nodeStruct *current = head;
	while (current != NULL) 
	{
		current = current->next;
		count++;
	}
	return count;
}
struct nodeStruct* List_findNode(struct nodeStruct *head, void* ptr)
{
	struct nodeStruct *current = head;
	while (current != NULL) 
	{
		if (current->ptr == ptr)
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node)
{
	assert(headRef != NULL);
	assert(*headRef != NULL);

	if (*headRef == node) 
	{
		*headRef = node->next;
	}
	else 
	{
		struct nodeStruct *previous = *headRef;
		while (previous->next != node) {
			previous = previous->next;
			assert(previous != NULL);
		}
		assert(previous->next == node);
		previous->next = node->next;
	}
	free(node);
}

struct nodeStruct* List_find_firstFit(struct nodeStruct *head, int size)
{
	struct nodeStruct *temp = head;
	while(temp != NULL)
	{
		if (*(long*)(temp->ptr) >= size)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
int check_next_header(struct nodeStruct *head,void* ptr)
{
	struct nodeStruct *temp = head;
	while(temp != NULL)
	{
		if (temp->ptr == ptr)
			return 1;
		temp = temp->next;
	}
	return -1;
}

void free_list_modify(struct nodeStruct *head,void* ptr, long header)
{
	struct nodeStruct *temp = head;
	while (temp != NULL)
	{
		if (temp->ptr == ptr)
		{
			
		}
	}
}




void List_sort (struct nodeStruct **headRef)
{
	while (doSinglePassOnSort(headRef)) {
		// Do nothing: work done in loop condition.
	}
}
static _Bool doSinglePassOnSort(struct nodeStruct **headRef)
{
	_Bool didSwap = false;
	while (*headRef != NULL) {
		struct nodeStruct *nodeA = *headRef;
		// If we don't have 2 remaining elements, nothing to swap.
		if (nodeA->next == NULL) {
			break;
		}
		struct nodeStruct *nodeB = nodeA->next;

		// Swap needed?
		if (nodeA->ptr > nodeB->ptr){
			swapElements(headRef, nodeA, nodeB);
			didSwap = true;
		}

		// Advance to next elements
		headRef = &((*headRef)->next);
	}
	return didSwap;
}
static void swapElements(struct nodeStruct **previous,struct nodeStruct *nodeA,struct nodeStruct *nodeB)
{
	*previous = nodeB;
	nodeA->next = nodeB->next;
	nodeB->next = nodeA;
}