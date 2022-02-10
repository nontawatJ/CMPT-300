#include "mystring.h"
#include <assert.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * The following are simple tests to help you.
 * You should develop more extensive tests to try and find bugs.
 */
int main()
{
/*	const int SIZE = 100;
	char buffer[SIZE];

	assert(mystrlen("cmpt 300") == 8);

	mystrcpy(buffer, "I am testing my string functions!");
	assert(strcmp(buffer, "I am testing my string functions!") == 0);


	assert(mystrcmp ("I love coding", "I love coding") == 0);

	char *dupStr = mystrdup(buffer);
	assert (!strcmp(buffer, dupStr));
	assert (buffer != dupStr);

	if (dupStr != NULL)
		free (dupStr);

	printf ("\nPassed VERY simple tests, remember to develop more tests.\n");*/

	int y=8;
	int* x=&y;
	printf("\n%d\n\n",*x);



/*	//test 2
	if (mystrlen("cmpt 300") == 8)
		printf("\ntrue\n\n");
	else
		printf("\nfalse\n\n");


	for (int i=0;i<5;i++)
	{
		buffer[i] = 't';
	}
	printf("%s\n\n",buffer);
	mystrcpy(buffer, "I am testing my string functions!");
	printf("%s\n\n",buffer);



	int test = mystrcmp ("I love coding", "I love coding");
	printf("%d\n\n",test);


	char *dup = mystrdup(buffer);
	if (dup != NULL)
	{
		printf("%s\n\n",dup);
		free(dup);
	}
*/



	//mystrcpy(buffer,)


	return 0;
}

