//
// Created by lwy on 2021/7/19.
//
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/sem.h>
#define SEM_KEY 4001
sem_t sem;
union semun{
    int val;
};
void sync(){
    int semid;
    semid=semget(SEM_KEY,1,IPC_CREAT|0666);
    union semun semun1;
    semun1.val=1;
    struct sembuf sembuf1;
    while(1){
        sembuf1.sem_num=1;
        sembuf1.sem_op=1;
        sembuf1.sem_flg=SEM_UNDO;
    }
}
