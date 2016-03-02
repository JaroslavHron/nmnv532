#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include <omp.h> 

int main(int argc, char *argv[]) 
{ 
	int procnum, numprocs; 
	int n, i; 
	double pi, h, sum, x, xi;

	n = 30; 	/* interval distribution */

        printf("We use %d subintervals\n", n); 
		
	h = 1.0 / (double) n; 
	sum = 0.0;
	
#pragma omp parallel for private(procnum,i,x,xi) reduction(+:sum) schedule(static,1) num_threads(4)
        for (i = 1; i <= n; i++) 
          { 
            xi=(double)i;
            x = h * (xi - 0.5); 
            sum += h* 4.0 / (1.0 + x*x);
 
            numprocs=omp_get_num_threads();
            procnum = omp_get_thread_num();
    
            printf ("Working - cpu %d out of %d on interval no. %d\n", procnum, numprocs,i);

          } 
        
        pi = sum;
        
        printf("pi is approximately %.16f, Error is %.16f\n", 
               pi, fabs(pi - M_PI));
	
	return 0;
} 
