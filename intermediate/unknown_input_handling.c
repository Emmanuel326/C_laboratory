#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int *numbers=NULL;
	int total_numbers =0;
	int allocated_slots=0;
	int current_input=0;

	puts("Enter numbers:");

	//keep reading till the user ends it
	while(scanf("%d", &current_input)==1)
	{
		//if our array is full resize
		if(total_numbers==allocated_slots)
		{
			allocated_slots=(allocated_slots==0)?2:allocated_slots*2;
			int *resized_memory=realloc(numbers, allocated_slots*sizeof(int));
			if(!resized_memory)
			{
				perror("Failed to realloc");
				free(numbers);
				exit(EXIT_FAILURE);
			}
			numbers = resized_memory;
		}
		//store input into our growing array
		numbers[total_numbers] = current_input;
		total_numbers++;
	}
	printf("\nyou entered %d numbers:\n", total_numbers);
	for(int i=0, i<total_numbers, i++)
		printf("%d", numbers[i]);
	printf("\n");
	free(numbers);
	numbers=NILL;


	return 0;
}


