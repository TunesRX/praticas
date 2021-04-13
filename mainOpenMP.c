#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>

int main(int argc, char **argv)
{
    double res = 0;
    int n = 100000;

    omp_set_num_threads(4);
    #pragma omp parallel 
    {
        double in = 0;
        double range = (1 - 0); 
        double div = RAND_MAX / range;
        time_t t;

        printf("There are %d threads. I'm thread %d\n", omp_get_num_threads(), omp_get_thread_num());
	    unsigned int seed = omp_get_wtime();
    #pragma omp for reduction (+:res)
        for(int j = 0; j< n ; j++) {
        
            double x = (rand_r(&seed) / div);
            double y = (rand_r(&seed) / div);
            
	        if((x*x + y*y) <= 1)
			    res ++;
	    }
    

    }
        
        // %s is format specifier
    double pi = (res/n)*4;
    printf("res: %lf ",res);
    printf("pi: %lf \n",pi);
    
    
    
   return 0;
}