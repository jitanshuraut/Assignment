def neville(xData, yData, x):
    m = len(xData)  # number of data points
    y = yData.copy()
    
    for k in range(1, m):
        y[0:m - k] = ((x - xData[k:m]) * y[0:m - k]\
                    + (xData[0:m - k] - x) * y[1:m - k + 1]) \
                    / (xData[0:m - k] - xData[k:m])

    return y[0]

# Example usage:
# xData = [1, 2, 3, 4]
# yData = [2, 1, 4, 3]
# x = 2.5
# result = neville(xData, yData, x)
# print(result)
