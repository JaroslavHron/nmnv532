#!/usr/bin/env python

import platform
from mpi4py import MPI

comm = MPI.COMM_WORLD

print "Hello! This is {2:s} cpu no {0:d} out of {1:d} cpus total.".format(comm.rank, comm.size, platform.node())

comm.Barrier()   # wait for everybody to synchronize
