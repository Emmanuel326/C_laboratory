#include <stdio.h>
#include <stdlib.h>

//so here is what realloc does:-
//yo OS, i had this box of 4 ints... now i need 8, can you 
//stretch it or should i move into a bigger box?
//
//
//if there is space right next to the block it extends it in place
// if not it allocates a new block, copies old contents, frees the old one and returns new ptr.
//
// 2.HERE IS A TYPICAL PATTERN.
 int *p =malloc(4*sizeof(int));// space for 4 int or 16 bytes
 for(int i=0; i<4; i++)
{
	p[i]=i+1;

}
p=realloc(p, 8*sizeof(int)); //asks for more space


for (int i=4; i<8; i++)
    p[i] = (i+1)*10;

for(int i=0; i<5; i++)
   printf("%d\n", p[i]);

   free(p);
   p=NULL;

   if (!p)
	printf("Watch out something is wrong");

	
//NEVER DO 
//p= realloc(p, new_size);
//if that fails --> p becomes NULL. you will have lost the original memory and the data.
//
//
////ALWAYS DO
int *tmp=realloc()p, new_size;
if (tmp == NULL)
{
	//reallo failed. old p is still valid
	perror("Realloc failed");
	free(p);
	exit(1)
}
p=tmp;


//SHRINKING MEMORRY
//example
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr =malloc(10 *sizeof(int));
	if(!arr)
	{
		perror("malloc failed");
		return EXIT_FAILURE;

	}

	for(int i=0; i<10; i++)
	{
		arr[i]=i+1;
	}

	//shrink the damn memory
	int *tmp = realloc(arr, 5*sizeof(int));
	if(!tmp)
	{
		perror("Realloc failed");
		return EXIT_FAILURE;
	}
	arr = tmp;

	printf("After shrinking...\n");
	for(int i=0; i<5; i++)
	{
		printf("%d ", arr[i]);
	    
	}
	printf("\n");

	free(arr);
	arr=NULL;
	return 0;

}
