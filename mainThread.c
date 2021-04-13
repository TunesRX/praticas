#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

pthread_t tid[2];

void* calc(void *n)
{
    double x, y;
    long res = 0;
    double range = (1 - 0); 
    double div = RAND_MAX / range;
    time_t t;

    srand((unsigned) time(&t));
    long io =   (long)n ;
    for(int i = 0; i< io; i++) {
        
        x = (rand() / div);
        y = (rand() / div);
	    if((x*x + y*y) <= 1)
			res ++;
	}
    
    return (void *)res;
}

int main(int argc, char **argv)
{
    if(argc != 3){
        printf("precisa do numero \n");
        return 0;
    }
    long n = atoi(argv[1]);
	long threadsN = atoi(argv[2]);
    double total = 0;

    for(int i = 0; i< threadsN ; i++) {
        int err = pthread_create(&(tid[i]), NULL, calc , (void *)(n/threadsN));
	}

    for(int i = 0; i< threadsN ; i++) {
        void *pe ;
        pthread_join(tid[i], &pe);
        total += (long  )pe;
    }

    
    // %s is format specifier
    double pi = (total/n)*4;
	printf("%lf \n",pi);
   return 0;
}