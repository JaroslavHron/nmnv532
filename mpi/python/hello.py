#!/usr/bin/env python

import platform
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank=comm.rank
size=comm.size

print "Hello! This is {2:4s} cpu no {0:4d} out of {1:4d} cpus total.".format(rank, size, platform.node())

comm.Barrier()   # wait for everybody to synchronize
