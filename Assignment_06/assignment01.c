/* From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes to complete and clean all of them. Hint: use loop to fork() multiple child processes. */


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
