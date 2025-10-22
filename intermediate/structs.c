#include <stdio.h>
#include <stdlib.h>


//structures or rather a struct lets you group related dat into one logica unit.
//it is like OOP concepts from oop oriented languages
//think of it as creating your own data type.


//1.DEFINING A STRUCT
struct Book
{
	char title[100];
	char author[100];
	int yearpublished;
	float price;
};

//the above says a book has a title an auther, the year of publication and a price tag.
//now we can create real ook entries in memory
//
int main()
{
	struct Book firstbook;

	strcpy(firstbook.title, "C programming from trenches");
	strcpy(firstBook.author, "Mad panda");
	firstBook.yearpublished =2001;
	firstBook.price=123.54;


	printf("Book: %s\n", firstBook.title);
	printf("Author: %s\n", firstBook.author);
	printf("Year: %d\n", firstBook.yearpublished);
	printf("price: %.2f\n", firstBook.price);


	return 0;
}


//#TYPEDEF FOR CLEAR NAMING.
typedef struct
{
	char title[100];
	char author[100];
	int year_of_publication;
	float price;


}Book;
//now with this you can just say Book, and that is it.
//STEP 4. Let us initiLIZE
 Book thirdbook=
{
	"Learn C like a samurai",
	"Dex and max",
	2012,
	23.43
};

//or you can initialize it partially

Book untitledBook = {.author="Unknown"}
//everything elde that is not set is defaulted to zeroes or empty strings.



