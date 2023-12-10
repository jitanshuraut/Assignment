import numpy as np


def printer(A):

    for i in range(0, len(A)):
        print(f'Vaule of X[{i}] = {A[i]}')


def luDecomp(a):
    n = len(a)
    a = np.array(a)

    for k in range(0, n-1):
        for i in range(k+1, n):
            if a[i, k] != 0.0:
                lam = a[i, k]/a[k, k]
                a[i, k+1:n] = a[i, k+1:n] - lam*a[k, k+1:n]
                a[i, k] = lam
    print(a)
    return a


def Lusolve(a, b):

    n = len(a)
    b = np.array(b)
    for k in range(1, n):
        b[k] = b[k] - np.dot(a[k, 0:k], b[0:k])

    b[n-1] = b[n-1]/a[n-1, n-1]
    for k in range(n-2, -1, -1):
        b[k] = (b[k] - np.dot(a[k, k+1:n], b[k+1:n]))/a[k, k]

    printer(B)


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
    a = luDecomp(A)
    Lusolve(a, B)
