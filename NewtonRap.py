import error
from numpy import sign

def newtonRaphson(f, df, a, b, tol=1.0e-9):
    fa = f(a)
    if fa == 0.0:
        return a
    fb = f(b)
    if fb == 0.0:
        return b
    if sign(fa) == sign(fb):
        error.err('Root is not bracketed')

    x = 0.5 * (a + b)
    
    for i in range(30):
        fx = f(x)
        if fx == 0.0:
            return x
        
        # Tighten the brackets on the root
        if sign(fa) != sign(fx):
            b = x
        else:
            a = x
        
        # Try a Newton-Raphson step
        dfx = df(x)
        
        # If division by zero, push x out of bounds
        try:
            dx = -fx / dfx
        except ZeroDivisionError:
            dx = b - a
        
        x = x + dx
        
        # If the result is outside the brackets, use bisection
        if (b - x) * (x - a) < 0.0:
            dx = 0.5 * (b - a)
            x = a + dx
        
        # Check for convergence
        if abs(dx) < tol * max(abs(b), 1.0):
            return x
    
    print('Too many iterations in Newton-Raphson')

# Example usage:
# Define your functions f(x) and df(x)
# result = newtonRaphson(f, df, a, b)
# print(result)
