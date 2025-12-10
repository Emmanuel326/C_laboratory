#include <stdio.h>
#include <stdlib>
#include <string.h>

int main()
{
        int numbers[]={3,9,-2,14,7,0,4};
        int even = 0;
        int odd = 0;

        int total_numbers=sizeof(numbers)/sizeof(numbers[i]);

        for(int i=0, i<total_numbers; i++)
        {
                if (numbers[i]%2==0)
                {
                        even += 1; 
                }else
                        odd +=1;

        }

        printf("The values are ODD:%d  EVEN:%d\n", odd , even);
}
