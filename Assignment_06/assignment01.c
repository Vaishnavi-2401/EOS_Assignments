#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int i, pid;

    for (i = 0; i < 5; i++) 
	{
        pid = fork();

        if (pid == 0)
		{									 // Child process
            for (int j = 0; j < 5; j++) 
			{
                printf("Child %d : Count = %d\n", getpid(), j + 1);
                sleep(1);
            }
            exit(0);

        } 
		else if (pid > 0) 
		{ 									// Parent process
            
        } 
		else 
		{
            perror("fork Failed!\n");
            return 1;
        }
    }

    for (i = 0; i < 5; i++) 
	{
        wait(NULL);
    }

    printf("All child processes are finished!\n");

    return 0;

}
