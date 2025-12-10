//a hashmap is an array of buckets + hash(key) function + collision handling 
//hash a key-> get and index ->
//go to bucket-> find your value
//buckets usually store linked lists or small arrays of 
//key/value pairs.

//a single key/value pain in a bucket

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
        char name [MAX_NAME];
        int age;
        //...other stuff
}person;

unsigned int hash(char *name)
{
        int length = strnlen(name, MAX_NAME);
        unsigned int hash_value=0;
        for(int i=0; i<length; i++)
        {
                hash_value +=name[i];
                hash_value=(hash_value * name[1])% TABLE_SIZE;
        }
        return hash_value;
}

int main()
{
        printf("Jacob => %u\n", hash("Jacob"));
        printf("Kevin => %u\n", hash("Kevin"));
        printf("Mark => %u\n", hash("Mark"));
        printf("Kelly => %u\n", hash("Kelly"));
        printf("Sam => %u\n", hash("Sam"));


        return 0;

}
