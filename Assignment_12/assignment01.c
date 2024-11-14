#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct Range 
{
    int start;
    int end;
}R;

int sum=0;

void *calculate_sum(void *parameter)
{
    R *range = (struct Range *)parameter;

    for (int i = range->start; i <= range->end; i++)
    {
        sum = sum + i;
    }
    return (void*)sum;
}

int main() 
{
    R r = {1, 20};

    pthread_t th1;

    pthread_create(&th1, NULL, calculate_sum, &r);

    pthread_join(th1, (void**)&sum);

    printf("Sum: %d\n", sum);

    return 0;
}
