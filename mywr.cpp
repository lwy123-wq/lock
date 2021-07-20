//
// Created by lwy on 2021/7/20.
//
#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

pthread_cond_t qready=PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock=PTHREAD_MUTEX_INITIALIZER;

void *read1(int w1,int r1){
    pthread_mutex_lock(&qlock);
    while (w1>0){
        pthread_cond_wait(&qready,&qlock);
    }
    pthread_mutex_unlock(&qlock);
}
void *unread1(int w1,int r1){
    pthread_mutex_lock(&qlock);
    cout<<"has change write and read"<<endl;
    if(w1==0){
        pthread_cond_signal(&qready);
    }
    pthread_mutex_unlock(&qlock);
}
void *write1(int w1,int r1){
    pthread_mutex_lock(&qlock);
    while (w1>0|| r1>0){
        pthread_cond_wait(&qready,&qlock);
    }
    pthread_mutex_unlock(&qlock);
}
void *unwrite1(int w1,int r1){
    pthread_mutex_lock(&qlock);
    if(w1==0&&r1==0){
        pthread_cond_signal(&qready);
    }
    pthread_mutex_unlock(&qlock);
}
