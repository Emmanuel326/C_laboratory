//We will learn how to use structs as function parameters
//let us say we wnat a function that prints books details


#include <stdio.h>
#include <stdlib.h>




	typedef struct
	{
		char title[100];
		char author[100];
		int yearpublished;
		float price;
	}Book;

	Book basic_c
	{
		"Learn C like a ninja",
		"DEX & Max",
		2012,
		24.99
	};



	void displayBookDetails(Book book)
	{
		printf("\nTitle: %s", book.title);
		printf("\nAuthor: %s", book.author);
		printf("\nyear: %d", yearpublished);
		printf("\nprice: %.2f\n", book.price);

	}

int main()
{
	Book book_in_store={"DSA, the heart of programming", "Dex", 2010, 44.50};
	displayBookDetails(book_in_store);
}

//This works fine but
//if we pass by value, the whole struct gets copied.
//
//PASSING STRCTS BY REFERENCE (tHE CLEANER AND EFFICIENT WAY)

void updateBookprice(Book *book_to_update, float newPrice)
{
	book_to_update -> price = newPrice;
}

//usage in main or wherever.
Book my_diary={"Pointer Magic", "Dex chaos", 2011, 30.56};
updateBookprice(&my_diary, 45.44);
printf("Updated price: %.2f\n", my_diary.price);


//the -> operator means fo to that struct pointer and access this member.


















//PASS STRUCT BY VALUE OVERVIEW
//you pass a copy of the struct
///this means the function works on its own local copy
//changes inside the function do not affet the original struct.


#include <stdio.h>

typedef struct
{
	char name[20];
	int score;
}player;

void show(player beginner)
{
	printf("Player: %s, score: %d\n ", beginner.name, beginner.score);
	beginner.score += 50; //this affects the copy only

}

int main()
{
	player champion ={"Dex", 100};
	show(champion);
	printf("After function: %d\n", champion.score); //still 100
}



//PASSING BY REFERENCE OVERVIEW 
//you pass the address of the struct(a pointer)
//this allows the function to directly modify the original struct.


#include <stdio.h>

typedef struct
{
	char name[100];
	int score;
}player;


void boost(player *junior)
{
	junior->score += 60;//modifies the original struct
}

int main()
{
	player senior={"max", 100};
	noost(&junior);
	printf("After function: %d\n", senior.score);//150
}
















