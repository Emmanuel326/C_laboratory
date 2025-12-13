#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
        int numbers[]={3,9,-2,14,7,0,4};
        int running_sum =0
        int max =numbers[0];
        

       int total_numbers=sizeof(numbers)/sizeof(numbers[i]);

        for(int i=0; i<total_numbers;i++)
        {
                running_sum += numbers[i];
                if (numbers[i]>max)
                
                {
                        max =numbers[i];
                }
                printf(" Numbers:%d  running-sum:%d  max:%d", numbers[i],  running_sum,  max);


                
        }

        return 0;
}


