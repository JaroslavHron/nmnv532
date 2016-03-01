#!/usr/bin/env python

import math
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank=comm.rank
ncpus=comm.size

n=0
if rank==0 :
    n = 30
    print "Using %d subintervals for %d cpus.\n"% (n, ncpus)

# send one int nuber to all from proces 0 - all others receive the number
sender=0;
n=comm.bcast(n, root=sender)

h = 1.0 / float(n)
sum_local = 0.0

print "cpu no %d: let me work on subintervals from %d with step %d"%(rank, rank+1, ncpus)
for i in range(rank+1, n, ncpus) :
    xi=float(i-1.0)
    x = h * (xi - 0.5)
    sum_local += h * 4.0 / (1.0 + x*x)

receiver=0
pi=0.0
pi=comm.reduce(sum_local, op=MPI.SUM, root=receiver)

if rank==0 :
    print "pi is approximately %.16f, Error is %.16f"%(pi, abs(pi - math.pi))

comm.Barrier()   # wait for everybody to synchronize
