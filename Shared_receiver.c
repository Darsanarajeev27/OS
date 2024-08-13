#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid = shmget((key_t)1222,1024,0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    printf("Key of the shared memory is: %d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    if (shared_memory == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from shared memory is %s\n",(char*)shared_memory);
    // Detach from the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    }    
    return 0;
}