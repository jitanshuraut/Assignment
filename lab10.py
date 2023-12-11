import numpy as np
import matplotlib.pyplot as plt

def cubic_spline(x, y, xi):
    n = len(x) - 1
    h = np.diff(x)
    a = y
    alpha = [(3/h[i]) * (a[i+1] - a[i]) - (3/h[i-1]) * (a[i] - a[i-1]) for i in range(1, n)]

    l = [1.0] * (n + 1)
    mu = [0.0] * n
    z = [0.0] * (n + 1)
    c = [0.0] * (n + 1)
    b = [0.0] * n
    d = [0.0] * n

    for i in range(1, n):
        l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i - 1] - h[i-1] * z[i - 1]) / l[i]

    for j in range(n-1, -1, -1):
        c[j] = z[j] - mu[j] * c[j+1]
        b[j] = (a[j+1] - a[j]) / h[j] - h[j] * (c[j+1] + 2 * c[j]) / 3.0
        d[j] = (c[j+1] - c[j]) / (3 * h[j])

    interval = 0
    for i in range(n):
        if x[i] <= xi <= x[i+1]:
            interval = i
            break

    dx = xi - x[interval]
    result = a[interval] + b[interval] * dx + c[interval] * dx**2 + d[interval] * dx**3

    return result

def neville(x, y, xi):
    n = len(x)
    Q = np.zeros((n, n))
    Q[:, 0] = y

    for i in range(1, n):
        for j in range(1, i + 1):
            Q[i, j] = ((xi - x[i - j]) * Q[i, j - 1] - (xi - x[i]) * Q[i - 1, j - 1]) / (x[i] - x[i - j])

    return Q[n - 1, n - 1]

x = [1, 2, 3, 4]
y = [1, 8, 27, 64]

xi_neville = np.linspace(min(x), max(x), 100)
yi_neville = [neville(x, y, xi) for xi in xi_neville]

xi_spline = np.linspace(min(x), max(x), 100)
yi_spline = [cubic_spline(x, y, xi) for xi in xi_spline]

plt.figure(figsize=(8, 6))
plt.scatter(x, y, label='Data Points', color='red')
plt.plot(xi_neville, yi_neville, label="Neville's Method", color='blue')
plt.plot(xi_spline, yi_spline, label='Cubic Spline', color='green')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()
plt.grid(True)
plt.title('Polynomial Interpolation using Neville and Cubic Spline')
plt.show()
