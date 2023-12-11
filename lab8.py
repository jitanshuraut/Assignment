import numpy as np

def first_central_difference(f, x, h):
    return (f(x + h) - f(x - h)) / (2 * h)

def first_non_central_difference(f, x, h):
    return (-f(x + 2 * h) + 4 * f(x + h) - 3 * f(x)) / (2 * h)

def second_non_central_difference(f, x, h):
    return (f(x + 2 * h) - 2 * f(x + h) + f(x)) / (h ** 2)

def function_to_approximate(x):
    return x**2

x = 2.0
h = 0.01

first_central_diff = first_central_difference(function_to_approximate, x, h)
print("First Central Difference Approximation:", first_central_diff)

first_non_central_diff = first_non_central_difference(function_to_approximate, x, h)
print("First Non-Central Difference Approximation:", first_non_central_diff)

second_non_central_diff = second_non_central_difference(function_to_approximate, x, h)
print("Second Non-Central Difference Approximation:", second_non_central_diff)
