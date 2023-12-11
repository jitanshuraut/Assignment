import numpy as np
from tabulate import tabulate

def matrix_multiply(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    return result

def get_identity_matrix(size):
    identity = [[0] * size for _ in range(size)]
    for i in range(size):
        identity[i][i] = 1
    return identity

def find_inverse(matrix):
    size = len(matrix)
    identity = get_identity_matrix(size)
    augmented_matrix = [row + identity[i] for i, row in enumerate(matrix)]

    # Perform Gauss-Jordan elimination to obtain the inverse
    for i in range(size):
        pivot = augmented_matrix[i][i]
        for j in range(i, size * 2):
            augmented_matrix[i][j] /= pivot
        for k in range(size):
            if k != i:
                factor = augmented_matrix[k][i]
                for j in range(i, size * 2):
                    augmented_matrix[k][j] -= factor * augmented_matrix[i][j]

    # Extract the inverse from the augmented matrix
    inverse = [row[size:] for row in augmented_matrix]
    return inverse

def get_minor(matrix, row, col):
    return [row[:col] + row[col + 1:] for row in (matrix[:row] + matrix[row + 1:])]

def calculate_determinant(matrix):
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    determinant = 0
    for col in range(len(matrix)):
        minor = get_minor(matrix, 0, col)
        determinant += matrix[0][col] * calculate_determinant(minor) * (-1) ** col
    return determinant

def print_matrix(matrix):
    print(tabulate(matrix, tablefmt="fancy_grid"))

def matrix_dot_product(matrix1, matrix2):
    rows1, cols1 = len(matrix1), len(matrix1[0])
    rows2, cols2 = len(matrix2), len(matrix2[0])

    if cols1 != rows2:
        raise ValueError("Number of columns in the first matrix must be equal to the number of rows in the second matrix.")

    result = [[0 for _ in range(cols2)] for _ in range(rows1)]
    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def take_matrix_input(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            value = float(input(f"Enter element at position ({i+1},{j+1}): "))
            row.append(value)
        matrix.append(row)
    return matrix

# Get the dimensions of the matrix from the user
rows_a = int(input("Enter the number of rows for matrix a: "))
cols_a = int(input("Enter the number of columns for matrix a: "))
print("----------------\n")

# Take input for matrix a
a = take_matrix_input(rows_a, cols_a)

rows_b = int(input("Enter the number of rows for matrix b: "))
cols_b = int(input("Enter the number of columns for matrix b: "))

# Take input for matrix b
b = take_matrix_input(rows_b, cols_b)

det_a = calculate_determinant(a)

if det_a != 0:
    inv_a = find_inverse(a)
    ans = matrix_dot_product(inv_a, b)
    print_matrix(ans)
else:
    print("Inverse of matrix 'a' does not exist.")
