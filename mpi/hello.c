#include <stdio.h>
#include <stdlib.h>

/* MPI header*/
#include <mpi.h>

extern char **environ;

int main(int argc, char *argv[])
{
  int numprocs;
  int procnum;
  
  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &procnum);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  
  printf ("Hello! This is cpu no %d out of %d cpus total.\n", procnum, numprocs);

  /*  int i = 1;
  char *s = *environ;

  for (; s; i++) {
    printf("%s\n", s);
    s = *(environ+i);
    }*/

  MPI_Finalize();

  return;
}
