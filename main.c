#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
int main(int argc, char **argv)
{
    if(argc != 2){
        printf("precisa do numero \n");
        return 0;
    }
    double n = atoi(argv[1]);
	double in = 0;
    double x, y;
    int res = 0;
    double range = (1 - 0); 
    double div = RAND_MAX / range;
    time_t t;

    srand((unsigned) time(&t));

    for(int i = 0; i< n ; i++) {
        
        x = (rand() / div);
        y = (rand() / div);
	    if((x*x + y*y) <= 1)
			res ++;
	}

    // %s is format specifier
    double pi = (res/n)*4;
	printf("%lf \n",pi);
   return 0;
}