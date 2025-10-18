#include <stdio.h>
#include  <stdlib.h>

 //we will go through malloc.
 //it is defined as void *malloc(size_t size);
 //example

int main()
{
	int *p=(int *)malloc(sizeof(int)); //allocate mem for 1 int
       if(!p)
       {
	       printf("Memory allocation failed\n");
	       return 1;
       }

       *p=42; //use the allocated mem
  	printf("Value: %d\n", *p);

	free(p);
	p=NULL;

	return 0;
}


//2.ALLOCATING AN ARRAY DYNAMICALLY
#include <stdio.h>
#include <stdlib.h>



int main()
{
	int n;
	printf("Enter size: ");
	scanf("%d", &n);


	int *arr=malloc(n *sizeof(int));
	if(!arr)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	printf("Array: ");
	for(int i=0;i<n;i++)
	{
		printf("%d", arr[i]);
	}

	free(arr);
	arr=NULL;
	return 0;
	//it is a subtle but un imaginably good practise to set pointer to NULL.
	//after free(p); do p=NULL;
	//if you leave it at free(p); then the pointer is freed  but still points to the old address and that can cause serious silent dangers
}
