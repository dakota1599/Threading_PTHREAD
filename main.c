#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * new_thread(void *num){
    pthread_t *threads = malloc(sizeof(pthread_t)*2);
    int *position = (int *)num;

    //Doing a depth of 4, which should make the height 2 to the power of 4.
    if(*position == 5){
        pthread_exit(NULL);
    }
    printf("This is a thread at level %d\n", *position);
    
    //Locks this code to prevent road jam.
    pthread_mutex_lock(&mutex);
    int n_num = *position+1;
    pthread_mutex_unlock(&mutex);

    for(int i = 0; i < 2; i++){
        pthread_create(&threads[i], NULL, new_thread, &n_num);
    }

    for(int i = 0; i < 2; i++){
        pthread_join(threads[i],NULL);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv){
    int start = 1;
    new_thread(&start);

    return 0;
}