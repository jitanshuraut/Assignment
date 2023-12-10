import numpy as np


def printer(A):

    for i in range(0, len(A)):
        print(f'Vaule of X[{i}] = {A[i]}')


def Gauss(A, B):
    print(A)
    print(B)
    A = np.array(A)
    B = np.array(B)
    n = np.shape(A)[0]
    # print(n[0])
    for k in range(0, n-1):
        for i in range(k+1, n):
            if (A[i, k] != 0):
                lam = A[i, k]/A[k, k]
                A[i, k+1:n] = A[i, k+1:n]-lam*A[k, k+1:n]
                B[i] = B[i]-B[k]

    for k in range(n-1, -1, -1):
        B[k] = (B[k] - np.dot(A[k, k+1:n], B[k+1:n]))/A[k, k]
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
    Gauss(A, B)
