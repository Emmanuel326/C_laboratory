//We will learn arrays of structs

//we start by defining a struct, just basic

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[50];
	int age;
	float averagescore;
}Student;
//each student has a  name, age and average score 
//that is a single unit of meaning.\


//function that prints all student data/info
void printAllStudents(Student students[], int totalStudents)
{
	for(int i=0; i<totalStudents; i++)
	{
		printf("%s (age %d) - score: %.1f\n",
				students[i].name,
				students[i].age,
				students[i].averagescore);
	}
}

int main()
{
	Student classList[3]=
	{
		{"dex",19,86.5},
		{"max",27, 89.2},
		{"frank",22, 77.6}

	};//an array with 3 students


	for(int studentindex=0; studentindex<3;studentindex++)
	{
		printf("Student %d: %s (Age %d)- score: %.1f\n",studentindex + 1,
				classList[studentindex].name,
				classList[studentindex].age,
				classList[studentindex].averagescore);
	}
	Student classList[3]=
	{
		{"dex",20,88.3},
		{"max",17,90},
		{"Ava", 23,90.4}
	};

	printAllStudents(classList, 3);

}


