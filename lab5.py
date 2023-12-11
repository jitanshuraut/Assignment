import numpy as np

def gauss_seidel(A, b, x0, tol=1e-6, max_iter=100):
    n = len(A)
    x = x0.copy()
    for iteration in range(max_iter):
        x_new = np.zeros_like(x)
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i+1:], x[i+1:])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]
        if np.all(np.abs(x - x_new) < tol):
            return x_new
        x = x_new
    raise ValueError("Gauss-Seidel method did not converge within the specified number of iterations")

# Define the coefficient matrix A and the right-hand side vector b
A = np.array([[4, -1, 0, 0],
              [-1, 4, -1, 0],
              [0, -1, 4, -1],
              [0, 0, -1, 3]])

b = np.array([30, 60, 70, 50])

# Initial guess for the solution
x0 = np.zeros_like(b)

# Solve the system using Gauss-Seidel
solution = gauss_seidel(A, b, x0)

# Print the solution
print("Solution:")
print(solution)
