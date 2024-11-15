#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 6

void* thread_fn(void *param)
{   
	int *arr = (int*)param;

	int i,j;

    for(i = 0; i < SIZE-1; i++)
    {
        for(j = i+1; j < SIZE; j++)
        {
            if(arr[i] > arr[j])
            {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
   
   			}
		}
	}
	return NULL;
}

int main() 
{

	int arr[SIZE] = {1,3,2,5,4,0};
    pthread_t th1;
    int ret;

    ret = pthread_create(&th1, NULL, thread_fn, arr);
    pthread_join(th1,NULL);

	printf("After sorting :\n");

	for(int i=0; i<SIZE; i++)
	{
		printf("%d\n",arr[i]);
	}
    return 0;
}

