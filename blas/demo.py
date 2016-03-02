import sys, timeit
import numpy as np
from scipy import linalg

A = np.array([[1,2],[3,4]])
x = np.zeros(2)
b = np.eye(2,1)

print A, b
print linalg.inv(A)
print A.dot(linalg.inv(A))

x=linalg.solve(A,b)
print x, A.dot(x)

