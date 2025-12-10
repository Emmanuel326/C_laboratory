#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()

{
        int values[]={3,9,-2,14,7,0,4};
        int n =sizeof(values)/sizeof(values[0]);

        int max=values[0];

        for(int i=1; i<n; i++)
        {
                if(values[i]>max)
                {
                        max=values[i];

                }
                
        }

        printf("max:%d\n", max);
        return 0;
}
