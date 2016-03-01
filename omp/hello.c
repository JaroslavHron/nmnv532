#include <stdio.h>
#include <stdlib.h>

/* OpenMP header*/
#include <omp.h>

int main(int argc, char *argv[])
{
  int numprocs;
  int procnum;
  
  numprocs=omp_get_num_threads();

  printf ("Hello! We are %d cpus total.\n", numprocs);

#pragma omp parallel private(procnum) num_threads(8)
  {

    numprocs=omp_get_num_threads();
    procnum = omp_get_thread_num();
    
    printf ("Hello! This is cpu no %d out of %d.\n", procnum, numprocs);
  }

  return;
}
