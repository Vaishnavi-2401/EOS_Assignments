#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 6

typedef struct bubbleSort 
{
    int *arr;
    int size;
} bs;

void *thread_fn(void *param)
{
    bs *b = (bs *)param;

    for (int i = 0; i < b->size - 1; i++)
	{
        for (int j = i + 1; j < b->size; j++)
		{
            if (b->arr[i] > b->arr[j]) 
			{
                int temp = b->arr[i];
                b->arr[i] = b->arr[j];
                b->arr[j] = temp;
            }
        }
    }

    return NULL;
}

int main()
{
    int arr[SIZE] = {1, 3, 2, 5, 4, 0};
    bs b = {arr, SIZE};
    pthread_t th1;
    int ret;

    ret = pthread_create(&th1, NULL, thread_fn, &b);

    pthread_join(th1, NULL);

    printf("After sorting :\n");

	for (int i = 0; i < SIZE; i++)
	{
        printf("%d\n", arr[i]);
    }
    return 0;
}
