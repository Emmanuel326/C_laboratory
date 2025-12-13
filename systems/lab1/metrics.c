#include "metrics.h"

static int sum = 0;
static int max = -9999; 

void metrics_add(int value)
{
        sum +=value;
        if(value>max)
        {
                max=value;
        }
}

int metrics_get_sum(void)
{
        return sum;
}

int metrics_get_max(void)
{
        return max;
}

