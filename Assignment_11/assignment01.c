#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>
#include <string.h>

#define SEM_KEY 0x4321

union semun 
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

void sigchld_handler(int sig) 
{
    int s;
    waitpid(-1, &s, 0);
}

int main() 
{
    int ret, i, semid;
    struct sigaction sa;
    union semun su;
    struct sembuf ops[1];

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigchld_handler;
    ret = sigaction(SIGCHLD, &sa, NULL);

    // Create a semaphore with a single counter
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0600);

    // Initialize semaphore counter to 1 (parent starts first)
    su.val = 1;
    ret = semctl(semid, 0, SETVAL, su);

    ret = fork();
    if (ret == 0) 
    { // Child process
        char *str = "INFOTECH\n";
        while (1) 
        {
            // Acquire the semaphore before printing the entire string
            ops[0].sem_num = 0;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);

            for (i = 0; str[i] != '\0'; i++) 
            {
                write(1, &str[i], 1);
                sleep(1);
            }

            // Release the semaphore after printing the entire string
            ops[0].sem_op = 1;
            semop(semid, ops, 1);
        }
    } else { // Parent process
        char *str = "SUNBEAM\n";
        while (1) 
        {
            // Acquire the semaphore before printing the entire string
            ops[0].sem_num = 0;
            ops[0].sem_op = -1;
            ops[0].sem_flg = 0;
            semop(semid, ops, 1);

            for (i = 0; str[i] != '\0'; i++) 
            {
                write(1, &str[i], 1);
                sleep(1);
            }

            // Release the semaphore after printing the entire string
            ops[0].sem_op = 1;
            semop(semid, ops, 1);
        }

        // Destroy semaphore
        semctl(semid, 0, IPC_RMID);
    }
    return 0;
}
