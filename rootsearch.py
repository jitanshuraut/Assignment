from numpy import sign

def rootsearch(f, a, b, dx):
    x1 = a
    f1 = f(a)
    x2 = a + dx
    f2 = f(x2)
    
    while sign(f1) == sign(f2):
        if x1 >= b:
            return None, None
        x1 = x2
        f1 = f2
        x2 = x1 + dx
        f2 = f(x2)
    
    return x1, x2

# Example usage:
# Define your function f(x)
# a, b, dx = 0.0, 5.0, 0.1  # Replace with appropriate values
# result = rootsearch(f, a, b, dx)
# print(result)
