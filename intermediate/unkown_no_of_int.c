#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr=NULL;
	int size=0;
	int capacity=0;
	int value;

	printf("Enter integers (ctrl + D ) ro end\n")
	//keep reading until EOF
	while(scanf("%d", &value)==1)
	{
		//if we are full double the capacity
		if(size==capacity)
		{
			capacity = (capacity ==0) ? 2: capacity*2;
			int *temp=realloc(arr, capacity*sizeof(int));
			if(!temp)
			{
				perror("failed");
				free(arr);
				exit(1);
			}
			arr=temp;
		}
		//store the value
		arr[size++]=value;

	}
	printf("\nYou entered %d numbers \n", size);
	for(int i=0; i<size;i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");

	free(arr);
	arr=NULL;
	return 0;

}
