#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

double takeTimes(double n){
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
	return pi;
}
int main(int argc, char **argv)
{
    clock_t start_t, end_t, total_t;
    total_t = 0;
    double n = 1000000;
    double res = 0;
    for(int i = 0; i<5; i++){
        start_t = clock();
        res = takeTimes(n);
        end_t = clock();
        total_t += (double)(end_t - start_t) ;
    }
   
   printf( " %f \n", total_t/5.0);
    
   return 0;
}