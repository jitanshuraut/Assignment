import numpy as np
import math


def decomp(a):
    n = len(a)

    for k in range(n):
        try:
            a[k, k] = math.sqrt(a[k, k]-np.dot(a[k:0, k], b[0:k]))
        except:
            print("error")

        for i in range(k+1, n):
            a[i, k] = (a[i, k]-np.dot(a[i, 0:k], a[k, 0:k]))/a[k, k]

    for k in range(n):
        a[0:k, k] = 0

    return a



def solve(l,b):
    n=len(l)

    for k in range (n):
        b[k]=(b[k]-np.dot(l[k, 0:k], b[0:k]))/l[k,k]

    for k in range(n-1,-1,-1):
        b[k]=(b[k]-np.dot(l[k+1:n,k],b[k+1:n]))/l[k,k]
    print(b)
    return b





n = int(input("Size :"))

A = []

for i in range(0, n):
    temp = []
    for j in range(0, n):
        x = int(input(f"Numer A[{i}][{j}]"))
        temp.append(x)
    A.append(temp)

B = []

for i in range(0, n):
    x = int(input(f"Numer B[{i}]"))
    B.append(x)

determinant = np.linalg.det(A)

if (determinant == 0):
    print("determinant = 0")
else:
    a=np.array(A)
    b=np.array(B)
    a=decomp(a)
    solve(a,b)
