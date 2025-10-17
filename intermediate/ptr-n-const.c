//1. const and pointers: 3 main patterns
//(a) pointer to const data
 const int *ptr=&x;

 //you can change the pointer but noy the value
 	
 int x=23, b =10;
 const int *ptr=&x;
 p=&b; //allowed

 *p = 45; //not allowed, error. Value is read only

//(b) a constant pointer to data 
int *const ptr=&x;

//you can change the value but not where it points to
int a=10, b=20;
int *const p=&a;
 *p =50; //This is allowed because it changes the value not the pointer
  p =&b; // we get an error for the pointer is const
	





  //(c) CONSTANT POINTER TO CONSTANT DATA.
  cont int *const ptr =&x;

  //in this form you cant change a thing simply because they are all constants. that is the nature of things
  const int x=45;
  const int *const p = &x;

  //p=&y; //it wont be necessary as it will result in an error.
  //*p = 10; // it wont change the value for it is a constant value.
  //
  //











  //2.FUNCTION PARAMETERS AND const
  //this is where they matter most
  //example
  void printArray(const int *arr, int n)
{
	for(int i=0; int<n; int++)
		printf("%d\n", arr[i]);

	//the array points to read only memory.you are not to modify the elements(that is a promise).
	//the callers's data is protected.
	
	void modify(int *arr); //modifies the array
	void read_only(const int *arr);// can not modify array
	
}


//3.POINTERS TO const IN STRUCTURES
//it is mostly used to protect internal data or immutable data
typedef struct
{
	const char *name;
	int age;
}person;
//name in this stryct points to a string literal or external memory that must not be modified.





//4.POINTERS TO POINTERS WITH const
int x=10;
int *p=&x;
int **pp =&p;

//constant pointer to pointer
int **const cpp=&p;

//pointer to const point
int *const *pcp=&p;


//pointer to pointer to const data
const int **ppc=&p;

/*You should avoid [casting away pointers] for it leads to undefined behaviour.
 * const int a=5;
 * int *p = (int *)&a; //it is dangerous
 * *p =10; //undefined behaviour
 * */

