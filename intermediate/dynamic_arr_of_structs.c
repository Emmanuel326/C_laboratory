#include <stdio.h>
#include <stdlib.h>

typedef  struct
{
	char name[50];
	int age;
	float averagescore;
}Student;

void printAllStudents(Student *studentList, int totalStudents)

{
	printf("\n--- Student List ---\n");
	for(int i=0;i<totalStudents;i++)
	{
		printf("%s (Age %d) - Score: %.1f\n");
	}


}


int main()
{
	int totalStudents;


	printf("Enter number of studnets");
	scanf("%d", &totalStudents);

	Student *studentList = malloc(totalStudents * sizeof(int));
	if(!studentList)
	{
		perror("Memmory allocation failed");
		exit(FAILURE_EXIT);
	}

	for(int studentIndex=0;studentindex<totalStudents; studentindex++) {
		printf("\nEnter details for student %d\n", studentindex +1);
	        puts("Name:");
		scanf("%s", &studentList[studentindex].name);

		puts("Age");
		scanf("%d",&studentList[studentindex]);

		puts("Average score:");
		scanf("%.1f", &studentList[studentindex]);

	}
	printAllStudents(studentList, totalStudents);

	free(studentList, totalStudents);
	studentList=NULL;

	return 0;
}
