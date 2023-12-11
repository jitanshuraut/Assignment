def func(x):
    return x*x*x - x*x + 2

def bisection(a, b):
    if func(a) * func(b) >= 0:
        print("You have not assumed right a and b\n")
        return

    while b - a >= 0.01:
        c = (a + b) / 2
        if func(c) == 0.0:
            break
        if func(c) * func(a) < 0:
            b = c
        else:
            a = c

    print("The value of root by Bisection is: ", "%.4f" % c)

def incremental(a, b):
    if func(a) * func(b) >= 0:
        print("You have not assumed right a and b\n")
        return
    
    step = 100
    while step > 0.0001:
        c = (a + b) / 2
        if func(c) == 0.0:
            break
        i = a
        while i < b:
            if func(i) * func(i + step) < 0:
                a = i
                b = i + step
                break
            i += step
        c = (a + b) / 2
        step /= 10

    print("The value of root by Incremental Search is: ", "%.4f" % c)

def DerFunc(x):
    return 3 * x * x - 2 * x

def newtonRaphson(x):
    h = func(x) / DerFunc(x)
    while abs(h) >= 0.0001:
        h = func(x) / DerFunc(x)
        x = x - h

    print("The value of the root by Newton Raphson is: ", "%.4f" % x)

newtonRaphson(2)
incremental(-2, 0)
bisection(-2, 0)
