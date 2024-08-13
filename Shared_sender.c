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
    shmid = shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("Key of the shared memory is %d\n",shmid);
    shared_memory = shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter some data to write to shared_memory: \n");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("You wrote %s\n",(char*)shared_memory);
    return 0;
}