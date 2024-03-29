def evalPoly(a, xData, x):
    n = len(xData) - 1  # Degree of polynomial
    p = a[n]
    for k in range(1, n + 1):
        p = a[n - k] + (x - xData[n - k]) * p
    return p

def coeffts(xData, yData):
    m = len(xData)  # Number of data points
    a = yData.copy()
    
    for k in range(1, m):
        a[k:m] = (a[k:m] - a[k - 1]) / (xData[k:m] - xData[k - 1])
    
    return a

# Example usage:
# xData = [1, 2, 3, 4]
# yData = [2, 1, 4, 3]
# coefficients = coeffts(xData, yData)
# x_value = 2.5
# result = evalPoly(coefficients, xData, x_value)
# print(result)
