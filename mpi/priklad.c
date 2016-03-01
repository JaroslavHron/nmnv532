#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#include "mpi.h" 

int main(int argc, char *argv[]) 
{ 
  int sender, receiver, ncpus; 
  int n, i, rank; 
  double sum_local, pi, h, x, xi;

  MPI_Init(&argc,&argv); 
  MPI_Comm_size(MPI_COMM_WORLD,&ncpus); 
  MPI_Comm_rank(MPI_COMM_WORLD,&rank); 
  
  if (rank == 0) {
    n = 30;
    printf("Using %d subintervals for %d cpus.\n", n, ncpus); 
  }
  
  /* send one int nuber to all from proces 0 - all others receive the number*/
  sender=0;
  MPI_Bcast(&n, 1, MPI_INT, sender, MPI_COMM_WORLD); 
  
  h = 1.0 / (double) n; 
  sum_local = 0.0;
  
  printf("cpu no %d: let me work on subintervals from %d with step %d\n",rank, rank+1, ncpus);
  for (i = rank + 1; i <= n; i += ncpus) 
    { 
      xi=(double)i;
      x = h * (xi - 0.5); 
      sum_local += h * 4.0 / (1.0 + x*x);
    } 
  
  receiver=0;
  MPI_Reduce(&sum_local, &pi, 1, MPI_DOUBLE, MPI_SUM, receiver, MPI_COMM_WORLD);
  
  if (rank == 0) 
    printf("pi is approximately %.16f, Error is %.16f\n", pi, fabs(pi - M_PI));
  
  MPI_Finalize(); 
  return;
}

