                                                                                                          
#include <pthread.h>
#include <stdio.h>
#include <unistd.h> 

int signal = 0;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *t_wait(void *);
void *t_signal(void *);


void t_wait(void){

   pthread_mutex_lock(&mutex);
   
   if(signal==0){
     printf("its not my turn let me sleep\n");
     pthread_cond_wait(&cond,&mutex);
   }
   
     printf("i got signal to do work\n");
     
     pthread_mutex_unlock(&mutex);
 }
 
 
 void *t_signal(void*ptr){
 
     sleep(2);
     pthread_mutex_lock(&mutex);
     
     signal==1;
     printf("resource locked\n");
     
     pthread_cond_signal(&cond);
     pthread_mutex_unlock(&mutex);
}


int main() {

    pthread_t t1, t2;
    int status1, status2;

    status1 = pthread_create(&t1, NULL, t_wait, NULL);
    status2 = pthread_create(&t2, NULL, t_signal, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
    
}