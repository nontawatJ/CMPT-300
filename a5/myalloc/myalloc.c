#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myalloc.h"
#include "list.h"

int header = 8;
int track = 0;
struct Myalloc {
    enum allocation_algorithm aalgorithm;
    int size;
    void* memory;
   
   //Some other data members you want, 
   //such as lists to record allocated/free memory
   struct nodeStruct *head_free;
   struct nodeStruct *head_allo;

}; struct Myalloc myalloc;


void initialize_allocator(int _size, enum allocation_algorithm _aalgorithm) {
    assert(_size > 0);
    myalloc.aalgorithm = _aalgorithm;
    myalloc.size = _size;
    myalloc.memory = malloc((size_t)myalloc.size);

    // Add some other initialization 
    //myalloc.head_free = List_createNode(_size - 8, 0, _size-1);


    //check if malloc work
    if (myalloc.memory == NULL)
    {
    	printf("malloc unsuccessful\n");
    	exit(-1);
    }
    //set all the content in memory to 0
    memset(myalloc.memory, 0, _size);
    //header for memory(8 bytes) that contain free space left
    *(long*)(myalloc.memory + 0) = (long)(_size - 8);
    myalloc.head_allo = NULL; //NULL cause we didnt put any value yet
    myalloc.head_free = List_createNode(myalloc.memory+0);//pointer point to start of memory
}

/*
void destroy_allocator() {
    free(myalloc.memory);

    // free other dynamic allocated memory to avoid memory leak
    struct nodeStruct *temp1;
    struct nodeStruct *temp2;

    temp1 = myalloc.head_allo;
    while(temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }

    temp1 = myalloc.head_free;
    while(temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }

}*/

void* allocate(int _size) {
	
    void* ptr = NULL;
    
    // Allocate memory from myalloc.memory 
    // ptr = address of allocated memory
    if (_size < 0)
    {
    	return ptr;
    }
    struct nodeStruct* allo_node;
    struct nodeStruct* free_node;
    struct nodeStruct* temp;

    if (myalloc.head_allo == NULL)
    {

/*    	printf("size of memory: %d\n",myalloc.size);
    	printf("actual free memory: %ld\n",*(long*)(myalloc.head_free->ptr));
    	printf("size of item is; %d\n", _size);
*/
    	if (*(int*)(myalloc.head_free->ptr) >= _size)
    	{

    		*(long*)(myalloc.memory+0) = (long)_size; //change the header to size of item
    		allo_node = List_createNode(myalloc.memory+0);
  			List_insertHead(&(myalloc.head_allo), allo_node); //insert in allo list
  			
  			long next_actual_free = myalloc.size - (_size + (header*2));
  			long next_header = header + _size;
  			*(long*)(myalloc.memory+next_header) = next_actual_free;
  			myalloc.head_free->ptr = myalloc.memory+next_header;
  			/*printf("header 1: %ld\n",*(long*)(myalloc.memory+0));
  			printf("allo list header 1: %d\n",*(int*)(myalloc.head_allo->ptr));
  			printf("header 2: %d\n",*(int*)(myalloc.memory+next_header));
  			printf("free list actual memory left: %ld\n",*(long*)(myalloc.head_free->ptr));*/

  			ptr = (myalloc.memory+header);

    	}
    }

    //first fit 
    else if (myalloc.aalgorithm == 0)
    {

    	if (track == 0)
    	{
            free_node = List_find_firstFit(myalloc.head_free,_size);
            if (free_node != NULL)
            {
                int prev_available_mem = available_memory();
                *(long*)(myalloc.memory+count_index(free_node->ptr)) = (long)_size;//change header to size of item
                allo_node = List_createNode(free_node->ptr);
                List_insertTail(&(myalloc.head_allo),allo_node);


                long next_header = count_index(free_node->ptr) + header + _size;
                if (check_next_header(myalloc.head_allo,myalloc.memory+next_header) == -1) //check if next header is already used return -1 if not return 1
                {
                    long next_actual_free = prev_available_mem - (_size + header);
                    *(long*)(myalloc.memory+next_header) = next_actual_free;
                    myalloc.head_free->ptr = myalloc.memory+next_header;
                    if (available_memory() < 0)
                    {
                        next_header = next_header - 7;
                        *(int*)(myalloc.memory+next_header) = available_memory()+header;
                        myalloc.head_free->ptr = myalloc.memory+next_header;
                        track = -1;

                    }
                
                }

                long temp3 = next_header - _size ;
                ptr = (myalloc.memory+temp3);
            }
        }
    	
    	
    }



    return ptr;
}


void deallocate(void* _ptr) {
    assert(_ptr != NULL);

    struct nodeStruct* alloChuck;
    int index = count_index(_ptr);
    alloChuck = List_findNode(myalloc.head_allo, _ptr);
    int size_of_data;

    //only one node allo list
    if ((index == 0) && (List_countNode(myalloc.head_allo) == 1))
    {
        *(long*)(myalloc.memory+0) = myalloc.size - 8;
        myalloc.head_free->ptr = myalloc.memory+0;
        List_deleteNode(&(myalloc.head_allo),alloChuck);
        return;
    }
    //it the last node in the allo list
    if ()


}

int compact_allocation(void** _before, void** _after) {
    int compacted_size = 0;

    // compact allocated memory
    // update _before, _after and compacted_size

    return compacted_size;
}

int available_memory() {
    int available_memory_size = 0;
    // Calculate available memory size
/*   	printf("in header 1: %ld\n",*(long*)(myalloc.memory+0));
   	printf("item inside mem: %d\n",*(long*)(myalloc.memory+header));
    printf("in header 2: %ld\n",*(long*)(myalloc.head_free->ptr));*/

    struct nodeStruct* temp = myalloc.head_free;
    while (temp != NULL)
    {
    	available_memory_size = available_memory_size + *(long*)(myalloc.head_free->ptr);
    	temp = temp->next;
    }



    return available_memory_size;
}

void print_statistics() {
    int allocated_size = 0;
    int allocated_chunks = 0;
    int free_size = 0;
    int free_chunks = 0;
    int smallest_free_chunk_size = myalloc.size;
    int largest_free_chunk_size = 0;

    // Calculate the statistics

    printf("Allocated size = %d\n", allocated_size);
    printf("Allocated chunks = %d\n", allocated_chunks);
    printf("Free size = %d\n", free_size);
    printf("Free chunks = %d\n", free_chunks);
    printf("Largest free chunk size = %d\n", largest_free_chunk_size);
   printf("Smallest free chunk size = %d\n", smallest_free_chunk_size);

}
long count_index(void* ptr)
{
    for (long i=0;i<myalloc.size;i++)
    {
        if ((myalloc.memory+i) == ptr)
            return i;
    }
}
