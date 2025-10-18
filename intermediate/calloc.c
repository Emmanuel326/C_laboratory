#include <stdio.h>
#include <stdlib.h>

//calloc stands for contiguous allocation
//it is malloc's cleaner twin


//the basic of it look like 
//void *calloc(size_t num, site_t size);
//you pass 2 arguments to calloc
//num --> no of elements
//size --> size of each element
//
int *arr = calloc(4, sizeof(int));
//the above is equivalent to 
//

int *arr = malloc(4 * sizeof(int));
memset(arr,0,4*sizeof(int));

//the initialization in calloc is handled internally.

