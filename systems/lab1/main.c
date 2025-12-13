#include <stdio.h>
#include "metrics.h"

int main()
{
        metrics_add(3);
        metrics_add(9);
        metrics_add(-2);
        metrics_add(14);
        metrics_add(7);
        metrics_add(0);
        metrics_add(4);
        metrics_add(5);

        printf("sum: %d\n", metrics_get_sum());
        printf("Max:%d\n", metrics_get_max());

        return 0;
}
