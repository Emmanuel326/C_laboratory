#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *arr=malloc(10 *sizeof(int));

	if(!arr)
	{perror("Error, did not allocate");
	exit(1)
	}
	for(int i=0; i<10; i++)
	{
		i + 1;
		printf("%d\n", arr[i]);
	}
		

	//realocate it 
	int *temp= realloc(arr, 5 * sizeof(int));
	if(!tmp){
		perror("reallocation failed");
		free(arr);
		arr=NULL;
 		exit(1);
	}arr=temp
	for(int i=0;i<5; i++)
	{
		printf("%d " , arr[i]);
		free(arr);
		arr=NULL;

		if(!arr)
			printf("Are you sure you wanna continue");


	}
return 0;
}
