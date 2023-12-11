import numpy as np
import time

# Gauss Elimination
def gauss_elimination(A, b):
    n = len(b)
    for i in range(n):
        if A[i, i] == 0.0:
            raise ValueError("Divide by zero detected!")

        for j in range(i + 1, n):
            ratio = A[j, i] / A[i, i]
            A[j, :] -= ratio * A[i, :]
            b[j] -= ratio * b[i]

    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]

    return x

# Gauss Elimination with Pivoting
def gauss_elimination_pivot(A, b):
    n = len(b)
    for i in range(n):
        pivot_row = max(range(i, n), key=lambda r: abs(A[r, i]))
        A[[i, pivot_row]] = A[[pivot_row, i]]
        b[i], b[pivot_row] = b[pivot_row], b[i]

        if A[i, i] == 0.0:
            raise ValueError("Divide by zero detected!")

        for j in range(i + 1, n):
            ratio = A[j, i] / A[i, i]
            A[j, :] -= ratio * A[i, :]
            b[j] -= ratio * b[i]

    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i+1:], x[i+1:])) / A[i, i]

    return x

# Doolittle Decomposition
def doolittle_decomposition(A):
    n = A.shape[0]
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    for i in range(n):
        L[i, i] = 1.0
        for j in range(i, n):
            U[i, j] = A[i, j] - np.dot(L[i, :i], U[:i, j])

        for j in range(i + 1, n):
            L[j, i] = (A[j, i] - np.dot(L[j, :i], U[:i, i])) / U[i, i]

    return L, U

# Choleski's Decomposition
def choleski_decomposition(A):
    n = A.shape[0]
    L = np.zeros((n, n))

    for i in range(n):
        for j in range(i + 1):
            if i == j:
                L[i, j] = np.sqrt(A[i, i] - np.dot(L[i, :i], L[i, :i]))
            else:
                L[i, j] = (A[i, j] - np.dot(L[i, :j], L[j, :j])) / L[j, j]

    return L

# Crout Decomposition
def crout_decomposition(A):
    n = A.shape[0]
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    for i in range(n):
        U[i, i] = 1.0

        for j in range(i, n):
            L[j, i] = A[j, i] - np.dot(L[j, :i], U[:i, i])

        for j in range(i + 1, n):
            U[i, j] = (A[i, j] - np.dot(L[i, :i], U[:i, j])) / L[i, i]

    return L, U

# Sample matrix and vector
A = np.array([[4, -2, 1],
              [-2, 4, -2],
              [1, -2, 4]], dtype=float)

b = np.array([11, -16, 17], dtype=float)

# Number of runs for timing measurements
num_runs = 100

# Gauss Elimination
total_time = 0
for _ in range(num_runs):
    start_time = time.time()
    x_gauss = gauss_elimination(A.copy(), b.copy())
    end_time = time.time()
    total_time += end_time - start_time

avg_time = total_time / num_runs
print(f"Gauss Elimination Solution: {x_gauss}")
print(f"Average Time taken for Gauss Elimination: {avg_time} seconds")

# Gauss Elimination with Pivoting
total_time = 0
for _ in range(num_runs):
    start_time = time.time()
    x_gauss_pivot = gauss_elimination_pivot(A.copy(), b.copy())
    end_time = time.time()
    total_time += end_time - start_time

avg_time = total_time / num_runs
print(f"Gauss Elimination with Pivoting Solution: {x_gauss_pivot}")
print(f"Average Time taken for Gauss Elimination with Pivoting: {avg_time} seconds")

# Doolittle Decomposition
total_time = 0
for _ in range(num_runs):
    start_time = time.time()
    L, U = doolittle_decomposition(A.copy())
    end_time = time.time()
    total_time += end_time - start_time

avg_time = total_time / num_runs
print("Doolittle Decomposition L:\n", L)
print("Doolittle Decomposition U:\n", U)
print(f"Average Time taken for Doolittle Decomposition: {avg_time} seconds")

# Choleski
