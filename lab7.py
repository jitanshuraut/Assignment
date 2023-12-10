class Data:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @staticmethod
    def interpolate(f: list, xi: float, n: int) -> float:
        # Initialize result
        result = 0.0

        for i in range(n):
            term = f[i].y

            for j in range(n):
                if j != i:
                    term *= (xi - f[j].x) / (f[i].x - f[j].x)

            # Add current term to result
            result += term

        return result

# Driver Code
if __name__ == "__main__":
    # Example usage
    data_points = [Data(1, 2), Data(2, 1), Data(3, 4), Data(4, 3)]
    xi_value = 2.5
    degree = len(data_points)

    result = Data.interpolate(data_points, xi_value, degree)
    print(result)





import numpy as np
import matplotlib.pyplot as plt

# Define the data points
x_data = np.array([0, 1, 2])
y_data = np.array([1, 3, 2])

# Define the range for plotting
x_range = np.linspace(0, 2, 1000)

# Function to compute the cardinal function for a specific index i
def cardinal_function(x, i, x_data):
    result = 1.0
    for j in range(len(x_data)):
        if j != i:
            result *= (x - x_data[j]) / (x_data[i] - x_data[j])

    return result

# Plot the cardinal functions
plt.figure(figsize=(12, 6))
for i in range(len(x_data)):
    y_cardinal = [cardinal_function(x, i, x_data) for x in x_range]
    plt.plot(x_range, y_cardinal, label=f"C{i+1}(x)")

# Plot the data points
plt.scatter(x_data, y_data, color="red", label="Data Points")

# Function to compute Lagrange's polynomial
def lagrange_polynomial(x, x_data, y_data):
    result = 0.0
    for i in range(len(x_data)):
        result += y_data[i] * cardinal_function(x, i, x_data)
    return result

# Compute and plot Lagrange's polynomial
y_lagrange = [lagrange_polynomial(x, x_data, y_data) for x in x_range]
plt.plot(x_range, y_lagrange, label="Lagrange's Polynomial", linestyle="--")

# Add labels and legend
plt.xlabel("x")
plt.ylabel("y")
plt.title("Cardinal Functions and Lagrange Polynomial")
plt.legend()
plt.grid()

# Show the plot
plt.show()


