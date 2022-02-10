
#ifndef LIST_H_
#define LIST_H_


struct nodeStruct
{
	void* ptr; //item pointed to the memory
	struct nodestruct* next;
};


struct nodeStruct* List_createNode(void* ptr);
void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node);
void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node);
int List_countNodes (struct nodeStruct *head);
struct nodeStruct* List_findNode(struct nodeStruct *head, void* ptr);
void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node);
void List_sort (struct nodeStruct **headRef);

struct nodeStruct* List_find_firstFit(struct nodeStruct *head, int size);
int check_next_header(struct nodeStruct *head,void* ptr);
void free_list_modify(struct nodeStruct *head,void* ptr, long header);

#endif