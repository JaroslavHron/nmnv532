import sys, timeit
import numpy as np
from scipy import linalg
from scipy.linalg.blas import (dasum, daxpy, ddot)

n=3000
x=np.array([float(i+1) for i in range(n)])

y=np.zeros(n)
for i in range(n):
    y[i]=float(i*i)

alpha=0.8
z=y.copy()

t=timeit.default_timer()
for i in range(10000) :
    for j in range(len(y)):
        y[j]+=alpha*x[j]
print "Time for native python vector combination:", timeit.default_timer()-t

y[:]=z[:]
t=timeit.default_timer()
for i in range(10000) :
    y[:]+= alpha*x[:]
print "Time for numpy vector combination:        ", timeit.default_timer()-t

y[:]=z[:]
t=timeit.default_timer()
for i in range(10000) :
    y = daxpy(x, y, a=alpha)
print "Time for BLAS vector combination:         ", timeit.default_timer()-t

