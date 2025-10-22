#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *arr=NULL;
	int size =0;
	int used=0;
	int value;

	while(scanf("%d ", &value)==1)
	{
		if(used==size)
		{
			size=(size==0)?2: size *2;
			int *temp = realloc(arr, size* sizeof(int));
			if(!temp)
			{
				perror("realloc failed");
				free(arr);
				arr=NILL;
				exit(1);
			}
			arr = temp;

		}
		arr[used++] = value;

	}
	printf("\nyou entered %d numbers: \n", used);
	for(int i=0; i<used; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");

	free(arr);
	arr=NILL;
	return 0;
}
